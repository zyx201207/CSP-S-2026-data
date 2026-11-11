#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxa;
bool flag=1;
bool cmp(long long a1,long long b){
    return a1>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxa=max(a[i],maxa);
    }
    for(int i=1;i<=n;i++){
        bool flag1=0;
        for(long long j=1;j<=maxa;j++){
            if(a[i]=pow(2,j)-1){
                flag1=1;
                break;
            }
        }
        if(flag1==0){
            flag=0;
            break;
        }
    }
    if(m==1){
       cout<<maxa;
       return 0;
    }
    if(flag==1){
        sort(a+1,a+n+1,cmp);
        cout<<a[m];
        return 0;
    }
    return 0;
}
