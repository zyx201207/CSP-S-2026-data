#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int t,n,c,d,x[N],cnt[N];

bool check(int l,int r){
	int len=r-l+1;
	for(int i=0;i<=len;i++)
		cnt[i]=0;
	int mask=(1<<(len-1))-1;
	for(int i=0;i<=mask;i++){
		int res=1e9,lst=0;
		for(int j=0;j<=len-2;j++){
			bool fl=(i>>j)&1;
			if(fl==0 && x[l+j+1]-x[l+lst]>d){
				res=1e9;
				break;
			}
			if(res==1e9) res=fl;
			else res+=fl;
			if(fl) lst=j;
		}
		if(x[r]-x[l+lst]>d) res=1e9;
		if(res==1e9) continue;
		res++;
		cnt[res]++;
	}
	for(int i=0;i<=len;i++){
		if(cnt[i]){
			return cnt[i]==2;
		}
	}
	return false;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(c>2){
			puts("0");
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				if(check(i,j)){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}