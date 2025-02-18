import math
class Solution:

    def closestDivisors(self, num):
        def findClosest(target):
            for i in range(int(math.sqrt(target)), 0, -1):
                if target % i == 0:
                    return [i, target // i]

        pair1 = findClosest(num + 1)
        pair2 = findClosest(num + 2)
        
        if abs(pair1[0] - pair1[1]) < abs(pair2[0] - pair2[1]):
            return pair1
        else:
            return pair2
