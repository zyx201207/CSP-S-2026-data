#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[200002],n,i,m,ans;
bool b[200002];
int ex(bool c[],int s,int d,int w){
    if(s==m&&ans<d) ans=d;
    if(ans>=d) return -1;
    int j=w-1;
    s++;
    while(j>-1){
        if(!b[j]){
            b[j]=true;
            if(ans>a[j]) break;
            int en=ex(c,s,d&a[j],j);
            if(en>ans) ans=en;
            b[j]=false;
        }
        j--;
    }
    return 0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    while(i<n){
        cin>>a[i];
        i++;
    }
    sort(a,a+n);
    i=n-1;
    while(i>-1){
        b[i]=true;
        if(ans>=a[i]) break;
        ex(b,0,a[i],i);
        b[i]=false;
        i--;
    }
    cout<<ans;
    return 0;
}
