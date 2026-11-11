#include<bits/stdc++.h>
using namespace std;
typedef long long la;
inline la read(){
    la ret,flag=1;char ch;
    while(!isdigit(ch=getchar()))if(ch=='-')flag=-1;
    ret=(la)ch-'0';
    while(isdigit(ch=getchar()))ret=ret*10+(la)ch-'0';
    return ret*flag;
}
const int N=5e5+10;
la a[N],b[N],ps[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)b[i]=a[i+1]-a[i];
    for(int i=1;i<n;i++)ps[i]=ps[i-1]+b[i];
    la sum=0,lstp=1,mx=0;
    for(int i=1;i<n;i++){
        la dis=i-lstp+1;
        sum+=dis*b[i];
        while(sum>m){
            sum-=(ps[i]-ps[lstp]);
            lstp++,dis--;
        }
        mx=max(mx,dis+1);
    }
    printf("%lld",mx);
    return 0;
}
