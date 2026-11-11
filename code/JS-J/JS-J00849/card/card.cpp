#include<bits/stdc++.h>
using namespace std;
#define TESTING
//#define HAND_PATH
void FREOPEN(const string& s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
namespace{
constexpr int N=500005,M=300005;
int v[N],ans[M];

void solve(){
	int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        stack<int> stk;
        vector<char> f(m+1,0);
        for(int j=i;j<=n;j++){
            if(!f[v[j]]){
                stk.push(v[j]);
                f[v[j]]=1;
            }else{
                while(stk.top()!=v[j]){
                    f[stk.top()]=0;
                    stk.pop();
                }
            }
        }
        while(!stk.empty()){
            ans[stk.top()]++;
            stk.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
#if !defined(NON_JUDGE) || defined(TESTING)
	FREOPEN("card");
#elif defined(HAND_PATH)
	string path;
	cin>>path;
	FREOPEN(path);
#endif
	solve();
	return 0;
}

