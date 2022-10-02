//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
  int LongestBitonicSequence(vector<int>nums)
  {
     
     
     int n = nums.size();
     
     vector<int> left(n,1);
     vector<int> right(n,1);
     
     
     for(int i=1;i<n;i++){
         int curr = nums[i];
         for(int j=i-1;j>=0;j--){
             if(curr > nums[j]){
                 left[i] = max(left[i],left[j]+1);
             }
         }
     }
     
     
     
     for(int i=n-2;i>=0;i--){
         int curr = nums[i];
         for(int j=i+1;j<n;j++){
             if(curr > nums[j]){
                 right[i] = max(right[i],1+right[j]);
             }
         }
     }
     
      int ans = 1;
      
     for(int i=0;i<n;i++){
          ans = max(ans,left[i]+right[i]-1);   
     }
     
     return ans;
  }
};

//{ Driver Code Starts.
int main(){
  int tc;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    vector<int>nums(n);
    for(int i = 0; i < n; i++)
      cin >> nums[i];
    Solution ob;
    int ans = ob.LongestBitonicSequence(nums);
    cout << ans <<"\n";
  }
  return 0;
}
// } Driver Code Ends