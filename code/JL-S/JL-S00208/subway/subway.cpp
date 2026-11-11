#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e2+5,M=5e5+5;
inline LL read(){
    LL num=0,sign=1;
    char ch=getchar();
    while(ch<'0' || ch>'9')
        sign=ch=='-' ? -1:1,ch=getchar();
    while(ch>='0' && ch<='9')
        num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
    return sign>0 ? num:-num;
}
LL c,n,m,d,q,w[M];
pair<LL,LL> at[N][25];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++) cin>>at[i][j].first>>at[i][j].second;
    }
    while(q--){
        int x=read(),y=read();
        LL ans=0;
        if(x>y) swap(x,y);
        ans+=w[x];
        for(int i=x;i<y;i++)
            ans+=at[i][1].second+at[i][2].second;
        ans+=w[y];
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
