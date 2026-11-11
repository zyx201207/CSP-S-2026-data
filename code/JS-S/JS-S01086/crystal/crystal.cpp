#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
//Oct31==Dec25?
int n,m,ans=-999999,ttt;
const int N=1000000;
int a[N],vis[N];
int main(){

    cin>> n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a[1],a[n]+1);
    int sum=0;
    for(int i=a[1];i<=a[n];i++){
        int t=m;
        for(int j=i-1;j>=1;j--){
            int v=i-a[j];
            t-=v;
            if(t>=0) {
              sum++;
            }
            if(t<0 && j==1) {
              int tt=ans;
              ans=max(sum,ans);
              if(ans>=tt){
                 ttt=i;
              }
              break;
            }
        }
        sum=0;
    }
    int anss=0;
    for(int i=1;i<=n;i++){
        if(a[i]==ttt)
        {
           anss++;
        }
    }
    cout<<ans+anss;
    return 0;
}
