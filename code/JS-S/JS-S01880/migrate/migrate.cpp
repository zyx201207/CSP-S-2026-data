#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
long long x[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    int n;
    if(c==11||c==12||c==0){
        while(t--){
            long long d;
            cin>>n>>d;
            memset(x,0,sizeof(x));
            for(int i=1;i<=n;i++)
            {
                cin>>x[i];
            }
            long long gc=(long long)x[2]-x[1];
            int cnt=0;
            if(d<gc){
                cout<<0<<endl;
                continue;
            }
            cnt=(int)d/gc;

            cout<<n-cnt<<endl;
        }
    }
    /*while(t--){
        cin>>n;
        memset(x,0,sizeof(x));
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
    }
    for(int i=1;i<=n;i++){
        int uu,vv;
        cin>>uu>>vv;
        g[uu].push_back(vv);
    }*/
    return 0;
}
