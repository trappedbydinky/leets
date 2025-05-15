class Solution:
    def rec(self, i, prev, words, groups, ans):
        if i == len(words):
            return
        if prev != groups[i]:
            ans.append(words[i])
        self.rec(i + 1, groups[i], words, groups, ans)

    def getLongestSubsequence(self, words, groups):
        ans = []
        self.rec(0, -1, words, groups, ans)
        return ans