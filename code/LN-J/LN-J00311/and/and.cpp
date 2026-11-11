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
const int N=2e5+10,M=31;
bool bits[N][M],flag[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n=read(),m=read(),ans=0;
    for(int i=1;i<=n;i++){
        int tin=read();
        for(int j=0;j<M;j++){
            if(tin&(1<<j))bits[i][j]=1;
        }
    }
    for(int i=M-1;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++)if(!flag[j])cnt+=bits[j][i];
        if(cnt>=m){
            ans+=1<<i;
            for(int j=1;j<=n;j++)if(!bits[j][i])flag[j]=true;
        }
    }
    printf("%d",ans);
    return 0;
}
