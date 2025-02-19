class Solution:
    def getHappyString(self, n, k):
        happy_strings = []
        
        def backtrack(curr):
            if len(curr) == n:
                happy_strings.append(curr)
                return
            for ch in "abc":
                if not curr or curr[-1] != ch:  # Ensure no consecutive characters are the same
                    backtrack(curr + ch)

        backtrack("")
        
        return happy_strings[k - 1] if k <= len(happy_strings) else ""
