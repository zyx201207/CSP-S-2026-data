#include<bits/stdc++.h>
using namespace std;
int n,m;
int maxn=-1;
int a[5001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(n>5005){
        cout<<"0";
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int sum1=0,to=0;
        for(int j=i;j>=1;j--){
            if(sum1+(a[i]-a[j])<=m){
                sum1+=(a[i]-a[j]);
                to++;
            }
        }maxn=max(maxn,to);
    }
    cout<<maxn;
    return 0;
}
