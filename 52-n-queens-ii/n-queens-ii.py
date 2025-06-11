class Solution:
    def totalNQueens(self, n):
        self.count = 0
        cols = set()
        pos_diags = set()
        neg_diags = set()

        def backtrack(row):
            if row == n:
                self.count += 1
                return
            for col in range(n):
                if col in cols or (row + col) in pos_diags or (row - col) in neg_diags:
                    continue
                cols.add(col)
                pos_diags.add(row + col)
                neg_diags.add(row - col)

                backtrack(row + 1)

                cols.remove(col)
                pos_diags.remove(row + col)
                neg_diags.remove(row - col)

        backtrack(0)
        return self.count
