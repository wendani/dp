class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m < 1 || n < 1) {
			return 0;
		}

		vector<int> pathNum(n, 1);
		for (int i = m - 2; i >= 0; i--) {
			for (int j = n - 2; j >= 0; j--) {
				pathNum[j] += pathNum[j + 1];
			}
		}
		return pathNum[0];
	}
};


class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m < 1 || n < 1) {
			return 0;
		}

		vector<vector<int>> pathNum(m, vector<int>(n, 0));
		for (int j = 0; j < n; j++) {
			pathNum[m - 1][j] = 1;
		}
		for (int i = 0; i < m - 1; i++) {
			pathNum[i][n - 1] = 1;
		}

		for (int i = m - 2; i >= 0; i--) {
			for (int j = n - 2; j >= 0; j--) {
				pathNum[i][j] += pathNum[i + 1][j];
				pathNum[i][j] += pathNum[i][j + 1];
			}
		}
		return pathNum[0][0];
	}
};


/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (49.19%)
 * Total Accepted:    336.3K
 * Total Submissions: 681.3K
 * Testcase Example:  '3\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * How many possible unique paths are there?
 *
 *
 * Above is a 7 x 3 grid. How many possible unique paths are there?
 *
 * Note: m and n will be at most 100.
 *
 * Example 1:
 *
 *
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Right -> Down
 * 2. Right -> Down -> Right
 * 3. Down -> Right -> Right
 *
 *
 * Example 2:
 *
 *
 * Input: m = 7, n = 3
 * Output: 28
 *
 */
