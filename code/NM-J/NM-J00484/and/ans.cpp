#include <bits/stdc++.h>

using namespace std;
long long dfs(int m,vector<int>arr,int ans,int first,int sum){
    int num=arr[first];
    if(m==0){
        ans=max(ans,sum);
        return ans;
    }
    sum&=num;
    dfs(m-1,arr,ans,first+1,sum);
    first+=1;

}
int main()
{
    //freopen("and.in","r",stdin);
    //freopen("ans.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector <int>arr;
    for(int i=0;i<n;i++){
        int h;
        cin>>h;
        arr.push_back(h);
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    int sum=arr[0];
    cout<<dfs(m,arr,ans,0,sum);
    return 0;
}
