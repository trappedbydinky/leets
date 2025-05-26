class Solution {
    public int shortestSequence(int[] omlate, int bklYeeLee) {
        Set<Integer> tehelkaOmlate=new HashSet<>();
        int yeeLee=0;
        for(int i=0;i<omlate.length;i++){
            tehelkaOmlate.add(omlate[i]);
            if(tehelkaOmlate.size()==bklYeeLee){
                tehelkaOmlate.clear();
                yeeLee++;
            }
        }
        return yeeLee+1;
    }
}