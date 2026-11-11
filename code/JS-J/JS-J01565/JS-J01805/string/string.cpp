#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,M=1e7+7;
vector<pair<int,char> > vp;
string s;
int maxf;
signed main(){
    freopen("string6.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int f;
        char c;
        cin>>f>>c;
        maxf=max(maxf,f);
        vp.push_back({f,c});
    };
    if(n*maxf<=1e8+1){
        for(auto x:vp){
            for(int i=1;i<=x.first;i++){
                s.push_back(x.second);
            }
        }
        int ans=0;
        for(int i=0;i<=s.size()/2-1;i++){
            if(s[i]!=s[s.size()-i-1])
                ans++;
        }
        cout<<ans;
    }
    else{
        int sx=vp[1].first;
        for(auto x:vp){
            sx=__gcd(sx,x.first);
        }
        for(auto x:vp){
            x.first/=sx;
            for(int i=1;i<=x.first;i++){
                s.push_back(x.second);
            }
        }
        int ans=0;
        for(int i=0;i<=s.size()/2-1;i++){
            if(s[i]!=s[s.size()-i-1])
                ans++;
        }
        cout<<ans*sx;
    }
    return 0;}
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
