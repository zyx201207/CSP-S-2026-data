#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define PII pair<int,int>
#define fi first
#define se second
#define inf 0x3f3f3f3f
using namespace std;
int C,_,n,f[2000003];
ll cnt[2000003],d,x[2000003];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>C>>_;
    while(_--){
        cin>>n>>d;
        int ans = 0;
        for(int i = 1;i<=n;i++)cin>>x[i];
        for(int i = 1,j = 1;i<=n;i++){
            while(j<=n && x[j]-x[i]<=d)j++;
            f[i] = j-1;
        }
        for(int i = 1;i<=n;i++){
            for(int j = i-1;j<=n;j++)cnt[j] = 0;
            cnt[i] = 1;cnt[i+1] = -1;
            int le = i,ri = i;
            while(1){
                int nle = ri+1,nri = f[ri];
                for(int j = le;j<=ri;j++)cnt[j]+=cnt[j-1],ans+=(cnt[j]==2);
                for(int j = le;j<=ri;j++)cnt[j] = min(cnt[j],1000000000ll);
                if(nle>nri)break;
                for(int j = le;j<=ri;j++)
                    if(f[j]>=nle)
                        cnt[nle]+=cnt[j],cnt[f[j]+1]-=cnt[j];
                le = nle,ri = nri;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
g++ -o migrate/migrate migrate/migrate.cpp -O2 -std=c++14 -static -Wall -Wshadow
*/