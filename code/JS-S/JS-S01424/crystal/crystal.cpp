#include<bits/stdc++.h>
using namespace std;
int n;
int a[500001],b[500001];
long long m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mx=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            b[j]=a[j]-a[i];
        }
        sort(b,b+n);
        int j=n-1,sum=0,t=0;
        while(sum<=m){
            if(j<0) break;
            if(b[j]<=0&&sum-b[j]<=m){
                sum-=b[j];
                t++;
            }
            j--;
        }
        if(t>mx) mx=t;
    }
    cout<<mx;
    return 0;
}
