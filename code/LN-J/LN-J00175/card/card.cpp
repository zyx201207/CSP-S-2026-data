#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int a[N],ans[N],t[N],t2[N];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ant=1,sb=1;
	while(n--){
		memset(t,0,sizeof(t));
		memset(t2,0,sizeof(t));
		ant=1;
		for(int cnt=sb;cnt<=n;cnt++){
			if(t[a[cnt]]){
				int flag=0;
				for(int i=1;i<=n;i++){
					if(t2[i]==a[cnt]){
						flag=1;
						ant=i;
					}
					if(flag){
						t2[i]=0;
						t[i]--;
					}
				}
				t2[ant]=a[cnt];
				ant++;
			}
			else{
				t[a[cnt]]=1;
				t2[ant]=a[cnt];
				ant++;
			}
		}
		for(int i=1;i<=m;i++){
			if(t[i])ans[i]++;
		}
		sb++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
