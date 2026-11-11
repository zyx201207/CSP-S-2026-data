#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5007;
int n,len;
int stdd,edd;
int a[maxn];
int val[maxn];
int sum[maxn];
int cnt[maxn];
void solve(){
	for(int i=1;i<=n;i++){
		val[i]=0;
	}
	int cur=1;
	int ans=0;
	for(int i=2;i<=n;i++){
		while(a[i]-a[cur]>len){
			cur++;
		}
		val[i]=val[cur]+1;
		if(val[cur+1]==val[cur]&&val[cur+2]!=val[cur]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return ;
}
int get(int x){
	int l=stdd-1,r=edd+1;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(cnt[mid]<=x){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	return l;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>len;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
//		if(c==11||c==12){
//			solve();
//		}
		int ans=0;
		for(int st=1;st<=n;st++){
			for(int i=1;i<=n;i++){
				val[i]=0;
				sum[i]=0;
				cnt[i]=1e18;
			}
			sum[st]=1;
			int cur=st;
			cnt[st]=0;
			stdd=st;
			for(int i=st+1;i<=n;i++){
				edd=i;
				while(abs(a[i]-a[cur])>len){
					cur++;
				}
				if(cur==i){
					break;
				}
				int cur2=get(cnt[cur]);
//				cout<<cur<<"  "<<cur2<<endl;
				cnt[i]=cnt[cur]+1;
				val[i]=(sum[cur2]-sum[cur-1]);
				if(val[i]==2){
					ans++;
				}
				sum[i]=sum[i-1]+val[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
