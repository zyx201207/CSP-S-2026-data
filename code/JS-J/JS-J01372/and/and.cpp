#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
vector<long long>mp[32];
set<long long>se;
inline void solve(int x){
    for(int i=0;i<32;i++){
        if(a[x]<(1<<i))break;
        if((a[x]&(1<<i))==(1<<i)){
            mp[i].push_back(x);
        }
    }
}
long long ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        solve(i);
    }
    for(int i=32;i>=0;i--){
        if(mp[i].size()>=m){
                //cout<<mp[i].size()<<endl;
            int cnt=0;
            if(se.size()==0){
               for(int x:mp[i]){
                se.insert(x);
                }
                 ans+=(1<<i);
            }
            else{
                int cnt=0;
                vector<long long>xx;
                for(int x:mp[i]){
                    if(se.count(x)){
                        cnt++;
                        xx.push_back(x);
                    }
                }
                    if(cnt>=m){
                        ans+=(1<<i);
                        se.clear();
                        for(int x:xx){
                            se.insert(x);
                        }
                    }
                }
            }
        }
    printf("%lld",ans);
return 0;
}

