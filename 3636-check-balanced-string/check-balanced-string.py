class Solution:
    def isBalanced(self, num):
        A = list(map(int, num))
        return sum(A[::2]) == sum(A[1::2])