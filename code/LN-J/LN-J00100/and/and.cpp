#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+10;
int a[N],maxn=-1;
bool cmp(int a,int b){
    return a>b;
}
int main (){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }
    if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
        return 0;
    }
    if(m==n){
        for(int i=2;i<=n;i++){
            a[i]&=a[i-1];
        }
        cout<<a[n];
        return 0;
    }else{
        sort(a+1,a+1+n,cmp);
        cout<<a[m];
    }

    return 0;
}
