#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n+1,0);
	vector<int>d(n+1,0);
	vector<int>pre(n+1,0);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
		pre[i]=pre[i-1]+d[i];
	}
	int L=1,R=n+1;
	while(L+1<R){
		int M=L+R>>1;
		int ck=1e18;
		int srt=0;
		for(int i=2;i<=M;i++){
			srt+=(i-1)*d[i];
		}
		ck=min(ck,srt);
		for(int i=3;i+M-2<=n;i++){
			int j=i+M-2;
			srt-=d[i-1];
			srt-=(pre[j-1]-pre[i-1]);
			srt+=d[j]*(M-1);
			ck=min(ck,srt);
		}
		if(ck<=m){
			L=M;
		}else{
			R=M;
		}
	}
	cout<<L<<endl;
}
