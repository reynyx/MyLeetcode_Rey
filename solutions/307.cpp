class BinaryIndexTree {
private:
    vector<int> BIT;
    int n;
public:
    // start from 1
    BinaryIndexTree(vector<int>& nums) {
        n = nums.size(); // [1 ... n]
        BIT = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i++) {
            update(i + 1, nums[i]);
        }
    }
    void update(int index, int value) {
        while (index <= n) {
            BIT[index] += value;
            index += lsb(index);
        }
    }
    int query(int index) {
        int res = 0;
        while (index) {
            res += BIT[index];
            index -= lsb(index);
        }
        return res;
    }
    int lsb(int x) {
        return x & (-x);
    }
};
class NumArray {
public:
    BinaryIndexTree* bit;
    vector<int> numsCache;
    NumArray(vector<int>& nums) {
        bit = new BinaryIndexTree(nums);
        for (auto num : nums) numsCache.push_back(num);
    }
    
    void update(int index, int val) {
        bit->update(index + 1, val - numsCache[index]);
        numsCache[index] = val;
    }
    
    int sumRange(int left, int right) {
        return bit->query(right + 1) - bit->query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */