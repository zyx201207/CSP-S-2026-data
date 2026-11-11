#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n=0,m=0;
    cin>>n>>m;
    if(m==1){
        cout<<0;
        return 0;
    }
    else if(m==2){
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            sum=max(sum,(nums[i]&nums[j]));
        }
    }
    cout<<sum;
    }
    else{
        int ans=1;
            vector<int> nums(n);
            for(int i=0;i<n;i++){
             cin>>nums[i];
             ans=ans&nums[i];
        }
        cout<<ans;
    }
    return 0;
}
