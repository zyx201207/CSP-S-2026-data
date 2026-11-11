#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
bool mp[N][31];
bool flag[N];
int cnt[31];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int st=-1;
	for(int i=0; i<n; ++i) {
		cin>>a[i];
		for(int j=0; j<30; ++j) {
			bool f=a[i]&(1<<j);
			mp[i][j]=f;
			cnt[j]+=f;
		}
	}
	for(int i=29;i>=0;--i){
		if(cnt[i]>=m){
			st=i;
			break;
		}
	}
	if(st==-1){
		cout<<0;
	}else{
		for(int i=0;i<n;++i){
			flag[i]=mp[i][st];
		}
		long long ans=(1<<st);
		for(int i=st-1;i>=0;--i){
			if(cnt[i]<m){
				continue;
			}
			int con=0;
			for(int j=0;j<n;++j){
				con+=(flag[j]&&mp[j][i]);
			}
			if(con>=m){
				ans+=(1<<i);
				for(int j=0;j<n;++j){
					flag[j]&=mp[j][i];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
