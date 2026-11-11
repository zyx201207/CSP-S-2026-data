#include<bits/stdc++.h>
using namespace std;
#define TESTING
//#define HAND_PATH

void FREOPEN(const string& s){
    if(!freopen((s+".in").c_str(),"r",stdin)){
        cerr<<"Can not open file:"<<s<<".in\n";
        return;
    }
    if(!freopen((s+".out").c_str(),"w",stdout)){
        cerr<<"Can not open file:"<<s<<".out\n";
        return;
    }
}
namespace{
int Case;
constexpr int N=2000005,FACTN=5005;
#define int long long
vector<int> e[N];
int v[N];
pair<int,int> dp[FACTN][FACTN];

void solve(){
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    if(n>=5000){
        cout<<0<<'\n';
        return;
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n&&v[j]-v[i]<=d;j++){
            e[i].push_back(j);
        }
    }
    for(int i=1;i<=n;i++){
        dp[i][i]={0,1};
        for(int j=i+1;j<=n;j++){
            dp[i][j]={0x3f3f3f3f,0};
        }
        for(int j:e[i]){
			dp[i][j]={1,1};
		}
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<k;i++){
            for(int j=k+1;j<=n;j++){
				//dp[k][j].first+dp[j][i].first
                //Floyd
                if(dp[i][k].first+dp[k][j].first<dp[i][j].first){
					dp[i][j].first=dp[i][k].first+dp[k][j].first;
					dp[i][j].second=dp[i][k].second*dp[k][j].second;
					//cout<<k<<" "<<j<<" "<<i<<" "<<dp[i][k].second*dp[k][j].second<<'\n';
				}else if(dp[i][k].first+dp[k][j].first==dp[i][j].first){
					dp[i][j].second+=dp[i][k].second*dp[k][j].second;
					//cout<<k<<" "<<j<<" "<<i<<" +="<<dp[i][k].second*dp[k][j].second<<'\n';
				}
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
			//cout<<"{"<<dp[i][j].first<<" "<<dp[i][j].second<<"} ";
            if(dp[i][j].second==2)ans++;
        }
        //cout<<"\n";
    }
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++){
        e[i].clear();
    }
}
void solve____l(){
    int T;
    cin>>Case>>T;
    while(T--){
        solve();
    }
}
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#if !defined(NON_JUDGE) || defined(TESTING)
    FREOPEN("migrate");
#elif defined(HAND_PATH)
    string path;
    cin>>path;
    FREOPEN(path);
#endif
    solve____l();
    return 0;
}
