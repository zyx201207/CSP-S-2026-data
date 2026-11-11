#include<bits/stdc++.h>
#define FILE_NAME "migrate"
using namespace std;
using lld=long long;
const int N=2000010;
int c,t,n;
lld d,x[N],nxt[N],bck[N],cnt[N];
vector<lld>rnxt[N],rbck[N];
int main(){
	freopen(FILE_NAME".in","r",stdin);
	freopen(FILE_NAME".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(cnt,0,sizeof(cnt));
		memset(nxt,0,sizeof(nxt));
		memset(bck,0,sizeof(bck));
		cin>>n>>d;
		for(int i=0;i<n;++i){
			rnxt[i].clear();
			rbck[i].clear();
		}
		for(int i=0;i<n;++i){
			cin>>x[i];
		}
		for(int i=1,ptr=0;i<n;++i){
			while(x[i]-x[ptr]>d){
				ptr++;
			}
			bck[i]=ptr;
			rbck[ptr].push_back(i);
		}
		for(int i=n-1,ptr=n-1;i>=0;--i){
			while(x[ptr]-x[i]>d){
				ptr--;
			}
			nxt[i]=ptr;
			rnxt[ptr].push_back(i);
		}
		lld ans=0;
		for(int i=n-1;i>=0;--i){
			int p=nxt[i];
			cnt[i]+=cnt[p];
			ans+=cnt[i];
			cnt[i]+=nxt[i]-i-rbck[i].size();
		}
		cout<<ans;
		cout<<"\n";
	}
	return 0;
}
