#include<bits/stdc++.h>
using namespace std;
long long n,c,a[2000005],head[4000005],tot,ver[4000005],nex[4000005],d,t,ans,val[4000005],sumval[4000005];
void dfs(int x){//cout<<x<<" ";
    for(int i=head[x];i!=0;i=nex[i]){
        int y=ver[i];
        if(val[x]+1<val[y]){
            if(sumval[y]==2) ans--;
            val[y]=val[x]+1;
            sumval[y]=1;
            dfs(y);
        }else if(val[x]+1==val[y]){
            sumval[y]++;
            if(sumval[y]==2) ans++;
            else if(sumval[y]==3) ans--;
            dfs(y);
        }
    }
}
void add(int g,int h){
    ver[++tot]=h;nex[tot]=head[g];head[g]=tot;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12){
            for(int k=1;k<=t;k++){
                cin>>n>>d;
                for(int i=1;i<=n;i++) cin>>a[i];
                long long t=a[2]-a[1];
                long long len=d/t;
                for(long long i=1;i<=len-1;i++){
                    ans+=n-(len+i+1)+1;
                }
                cout<<ans<<"\n";
                ans=0;
                for(int i=1;i<=n;i++) a[i]=0;
            }
            return 0;
    }
    for(int k=1;k<=t;k++){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            long long j=i+1,sum=a[i+1]-a[i];
            while(sum<=d&&j<=n){
                add(i,j);
                add(j,i);
                j++;
                sum=a[j]-a[i];
            }
        }
        for(int i=1;i<=n;i++){
            memset(val,0x3f,sizeof(val));
            memset(sumval,0,sizeof(sumval));
            val[i]=0;
            dfs(i);
        }
        cout<<ans/2<<"\n";
        memset(head,0,sizeof(head));
        memset(ver,0,sizeof(ver));
        memset(nex,0,sizeof(nex));
        tot=0;
        ans=0;
    }
    return 0;
}
