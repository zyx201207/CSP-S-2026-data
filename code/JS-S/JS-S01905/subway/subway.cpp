#include <bits/stdc++.h>
using namespace std;
const int N=500002;
long long M=1e18;
struct lll{
    long long tt;
    int di;
};
int c,n,m,d,q,tiao[502];
long long mp[502][502];
long long w[N],ab[N];
vector<lll>t[N];
int main()
{
    /*freopen("subway7.ans","r",stdin);
    int oo=0;
    while(cin>>ab[++oo]){
        continue;
    }
    fclose(stdin);*/
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    //cout<<n<<' '<<m<<' '<<q<<endl;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)if(i==j)mp[i][j]=0;else mp[i][j]=M;
    for(int i=1;i<=n;i++){
        cin>>tiao[i];
        for(int j=1;j<=tiao[i];j++){
            lll aa;
            int zhan;
            aa.di=i;
            cin>>zhan>>aa.tt;
            t[zhan].push_back(aa);
            int l=t[zhan].size();
            for(int k=0;k<l-1;k++){
                if(t[zhan][k].tt+aa.tt<mp[i][t[zhan][k].di])
                mp[t[zhan][k].di][i]=mp[i][t[zhan][k].di]=t[zhan][k].tt+aa.tt;
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(mp[i][j]>mp[i][k]+mp[k][j])
                mp[i][j]=mp[i][k]+mp[k][j];
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        cout<<mp[i][j]<<' ';
        cout<<endl;
    }*/
    int po=0;
    bool bbb=0;
    while(q--){
        int fr,to;
        long long ans=M;
        cin>>fr>>to;
        int l1=t[fr].size(),l2=t[to].size();
        for(int i=0;i<l1;i++){
            for(int j=0;j<l2;j++){
                    if(ans>mp[t[fr][i].di][t[to][j].di]+t[fr][i].tt+t[to][j].tt)
                        ans=mp[t[fr][i].di][t[to][j].di]+t[fr][i].tt+t[to][j].tt;
            }
        }
        cout<<ans+w[fr]+w[to]<<endl;
    }
    //if(bbb==0)cout<<1<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
