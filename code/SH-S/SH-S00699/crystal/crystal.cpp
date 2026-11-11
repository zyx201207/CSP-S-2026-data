#include<bits/stdc++.h>
#define int int64_t
#define cin fin
#define cout fout
using namespace std;
ifstream fin("crystal.in");
ofstream fout("crystal.out");
int n,m;
vector<int> arr;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    arr.assign(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(),arr.end());
    int ans=1,i=0,j=1;__int128_t sum=arr[0];
    while(i<j&&j<n){
        while(arr[j]*(j-i)-sum<=m&&j<n){
            sum+=arr[j++];
        }
        ans=max(j-i,ans);
        while(arr[j]*(j-i)-sum>m){
            sum-=arr[i++];
        }
    }
    cout<<ans;
}
