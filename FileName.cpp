#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<numeric>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
        vector<int> res;
        while (true) {
            for (int i = l; i <= r; i++) res.push_back(matrix[t][i]); // left to right
            if (++t > b) break;
            for (int i = t; i <= b; i++) res.push_back(matrix[i][r]); // top to bottom
            if (l > --r) break;
            for (int i = r; i >= l; i--) res.push_back(matrix[b][i]); // right to left
            if (t > --b) break;
            for (int i = b; i >= t; i--) res.push_back(matrix[i][l]); // bottom to top
            if (++l > r) break;
        }
        return res;
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int row = matrix.size(), col = matrix[0].size();
        int i = 0;
        for (i = 0; i < row / 2; i++) {
            for (int j = i; j < col - i; j++)res.push_back(matrix[i][j]);
            for (int j = i + 1; j < row - i - 1; j++)res.push_back(matrix[j][col - 1 - i]);
            for (int j = i; j < col - i; j++)res.push_back(matrix[row - 1 - i][col - 1 - j]);
            if (col - 1 - i != i)
                for (int j = i + 1; j < row - i - 1; j++)res.push_back(matrix[row - 1 - j][i]);
            else break;
        }
        if (row <= col && row % 2 != 0)for (int j = i; j < col - i; j++)res.push_back(matrix[i][j]);
        return res;
    }
};
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 1)return x;
        else if (n == -1)return 1 / x;
        else if (n == 0)return 1;
        return myPow(x, n / 2) * myPow(x, n / 2) * myPow(x, n % 2);
    }
};
class Solution {
public:
    double myPow(double x, int N) {
        double ans = 1;
        long long n = N;
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        while (n) {
            if (n & 1) {
                ans *= x;
            }
            x *= x;
            n >>= 1;
        }
        return ans;
    }
};
class Solution {
public:
    string add(string num1, string num2) {
        string num3 = "";
        int add_in = 0;
        int i = 0, j = 0;
        while (i < num1.length() && j < num2.length()) {
            int a = num1[i] - '0', b = num2[j] - '0';
            char c = (a + b + add_in) % 10 + '0';
            add_in = (a + b + add_in) / 10;
            num3 += c;
            i++; j++;
        }
        while (i < num1.length()) {
            int a = num1[i] - '0';
            char c = (a + add_in) % 10 + '0';
            add_in = (a + add_in) / 10;
            num3 += c;
            i++;
        }
        while (j < num2.length()) {
            int b = num2[j] - '0';
            char c = (b + add_in) % 10 + '0';
            add_in = (b + add_in) / 10;
            num3 += c;
            j++;
        }
        if (add_in != 0)
            num3 += add_in + '0';
        return num3;
    }
    string multiply(string num1, string num2) {
        string res = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num1.length(); i++) {
            string num3 = "";
            int mul_in = 0;
            int a = num1[i] - '0';
            for (int j = 0; j < num2.length(); j++) {
                int b = num2[j] - '0';
                num3 += (a * b + mul_in) % 10 + '0';
                mul_in = (a * b + mul_in) / 10;
            }
            if (mul_in != 0)
                num3 += mul_in + '0';
            if (i == 0)
            {
                res = num3;
                continue;
            }
            string temp(i, '0');
            num3 = temp + num3;
            res = add(res, num3);
        }
        reverse(res.begin(), res.end());
        int len = 0;
        while (len < res.length() && res[len++] == '0') {}
        string result(res.begin() + len - 1, res.end());
        return result;
    }
};
class Solution {
public:
    string RLE(string s) {
        int len = 1;
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            while (i<s.length()-1&&s[i] == s[i + 1]) {
                len++;
            }
            res += to_string(len);
            res += i;
            len = 1;
        }
        return res;
    }
    string countAndSay(int n) {
        if (n == 1)return "1";
        return RLE(countAndSay(n - 1));
    }
};
class Solution {
public:
    int Binary_search1(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] < target)l = m + 1;
            else r = m;
        }
        return nums[l] == target ? l : -1;
    }
    int Binary_search2(vector<int>& nums, double target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] < target)l = m + 1;
            else r = m;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l, r;
        if (Binary_search1(nums, target) == -1)return vector<int>(2, -1);
        l = Binary_search1(nums, target);
        r = Binary_search2(nums, target + 0.5);
        return vector<int>{ l,r };
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if ((nums[mid] <= nums[0] && nums[0] < nums[target] && nums[target] < nums[mid])
                || !(nums[mid] > nums[0] && nums[target]<nums[0] && nums[target]>nums[mid]))
                right = mid;
            else left = mid + 1;
        }
        return (left == right && nums[left] == target) ? left : -1;
    }
};