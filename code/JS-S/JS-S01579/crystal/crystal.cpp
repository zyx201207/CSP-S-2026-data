#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans=0;
vector<int> v;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    if(n<=5000){
        for(int i=1;i<=n;i++){
            v.clear();
            for(int j=1;j<=i;j++){
                v.push_back(a[i]-a[j]);
            }
            sort(v.begin(),v.end());
            ll c=0,cnt=0;
            bool f=0;
            for(int i=0;i<v.size();i++){
                if(c+v[i]<=m){
                    cnt++;
                    c+=v[i];
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
    }else{
        bool f=1;
        for(int i=1;i<=n;i++){
            if(a[i]!=i) f=0;
        }
        if(f){
            ll cc=0,cnt=0;
            for(int i=0;i<=n-1;i++){
                if(cc+i<=m){
                    cnt++;
                    cc+=i;
                }
            }
            cout<<cnt;
            return 0;
        }
        set<int> se;
        for(int i=1;i<=n-1;i++){
            se.insert(a[i+1]-a[i]);
        }
        if(se.size()==1){
            ll ccc=0,cnt=0;
            ll cha=a[2]-a[1];
            for(int i=0;i<=(n-1)*cha;i+=cha){
                if(ccc+i<=m){
                    cnt++;
                    ccc+=i;
                }
            }
            cout<<cnt;
            return 0;
        }

    }
    return 0;
}
