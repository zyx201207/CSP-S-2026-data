#include<bits/stdc++.h>
using namespace std;
long long a[200020];
int b[25];
long long y(int l,int r){
    long long cnt=0,wq=1;
    while(l>0&&r>0){
        if(l%2==1&&r%2==1)
            cnt+=wq;
        l/=2;
        r/=2;
        wq*=2;
        }
    return cnt;}
int tx(int f,int l){
    int ans=0,zb=23;
    for(int i=1;i<l;i++){
        if(y(f,a[i])>ans&&(!b[zb])){
            ans=y(f,a[i]);
            zb=i;
        }
    }
    b[zb]=1;
    return ans;}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,t=1;
    long long cnt=-1,x;
    cin>>n>>m>>a[1];
    x=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        x=y(x,a[i]);
    }
    if(m==n)
    {
        cout<<x;
        return 0;
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++){
                cnt=max(cnt,y(i,j));}
        }
    cout<<cnt;
    return 0;
    }
    if(n<=20){
        x=a[n];
        while(m>1){
            x=tx(x,n);
            m--;
        }
    cout<<x;
    }
    else
    {cout<<a[n-m];}
    return 0;}
