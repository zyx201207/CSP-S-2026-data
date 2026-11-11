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
const int N=5e5+10,M=3e5+10;
int a[N],lst[M],ans[M],tag[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        lst[a[i]]=i;
        ans[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans[a[i]]++;
            j=lst[a[i]]+1;
        }
    }
    for(int i=1;i<=m;i++)printf("%d ",ans[i]);
    return 0;
}
