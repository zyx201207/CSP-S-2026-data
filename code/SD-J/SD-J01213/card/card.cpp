#include<bits/stdc++.h>
using namespace std;

int n,m;
const int N=5e5;
int a[N+5];
int ans[N+5];
int last[N+5];
long long c[N+5];
pair<int,int>cnt[N+5];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	bool flag=true;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]>a[i-1]) flag=false;
	}
	if(flag) {
		for(int i=1; i<=n; i++) {
			ans[a[i]]++;
		}
		for(int i=1; i<=m; i++) ans[i]=ans[i-1]+ans[i];
		for(int i=1; i<=m; i++) cout<<ans[i]<<" ";
		cout<<endl;
	} else {
		if(m<=2) {
			if(m==1) cout<<n<<endl;
			else {
				for(int i=1; i<=n; i++) {
					if(a[n]!=a[i]) {
						ans[a[i]]++;
						ans[a[n]]++;
					} else ans[a[i]]++;
				}
				cout<<ans[1]<<" "<<ans[2]<<endl;
			}
		} else {
			long long cntj=0;
			for(int i=1; i<=n; i++) {
				if(last[a[i]]!=0) {
					cnt[++cntj].first=last[a[i]];
					cnt[cntj].second=i;
//				cout<<last[a[i]]<<" "<<i<<endl;
				}
				last[a[i]]=i;
			}
//		cout<<endl;
			sort(cnt+1,cnt+cntj+1);
			for(int i=1; i<=n; i++) {
				long long las=0;
				for(int j=1; j<=cntj; j++) {
					if(cnt[j].first>=i) {
						if(cnt[j].first>=las) {
							c[cnt[j].first]++;
							c[cnt[j].second]--;
							las=cnt[j].second;
						}
					}
				}
				for(int j=i; j<=n; j++) {
					c[j]=c[j-1]+c[j];
//				cout<<c[j]<<" ";
					if(c[j]==0) {
						ans[a[j]]++;
//					cout<<a[j]<<" ";
					}
				}
				for(int j=i; j<=n; j++) c[j]=0;
//			cout<<endl;
			}
//		cout<<endl;
			for(int i=1; i<=m; i++) cout<<ans[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}
