#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    vector<char> ans;
    while(n--){
        int a;
        cin>>a;
        char n;
        cin>>n;
        for(int i=0;i<a;i++){
            ans.push_back(n);
        }
    }
    int left=0,right=ans.size()-1;
    int sum=0;
    while(left<right){
        if(ans[left]!=ans[right]){
            sum++;
        }
        left++;
        right--;
    }
    cout<<sum;
    return 0;
}
