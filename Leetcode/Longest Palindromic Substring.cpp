class Solution {
public:
    string longestPalindrome(string s) {
        
        int size = s.size();
        
        int max_len =  1;
        int start_pos = 0;
       
        
        for(int i=0; i<size; i++){
            
            //assuming central letter is not fixed
            int st = i;
            int end = i;
            
            
            while(st >=0 and end<size and s[st]==s[end]){
                st--;
                end++;
            }
             st++;
            end--;
            if(max_len < end-st+1){
               max_len = end-st+1;
                start_pos = st;
            }
            
            
             st = i;
             end = i+1;
            
            //assuming central character is fixed
            while(st >= 0 and end < size and s[st]==s[end]){
                st--;
                end++;
            }
             st++;
            end--;
            if(max_len < end-st+1){
               max_len = end-st+1;
                start_pos = st;
            }
            
            
            
        }
         return s.substr(start_pos,max_len);
    }
};