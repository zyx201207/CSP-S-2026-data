#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d,s,rty;
int x[2000005];
int a[2000005];
vector<int> h;
bool ok(int c){
	int s=1;
	while(1){
		s=a[s];
		if(a[s-1]==a[s]&&a[s]<=c)return 1;
		if(s>=c||s==a[s])break;
	}
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
	//	cout<<"rty"<<'\n';
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n==1){
			cout<<"0"<<'\n';
			continue;
		}
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			int u=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
			a[i]=u;
		}
		int hh=0ll;
		for(int i=1;i<=n;i++){
			h.clear();
			s=i;
			rty=0ll;
			while(1){
				s=a[s];
				h.push_back(s);
				rty++;
				if(s==n||s==a[s])break;
			}
			int sl=0ll,sr=0ll,sum=0ll;
			for(int j=0;j<h.size();j++){
				if(j==0&&h[j]==i+1)continue;
				else if(j!=0&&h[j]==h[j-1]+1)continue;
				else if(sr>=h[j]-1)continue;
				else if(ok(h[j]-1))continue;//判断是否只有一条路可以到达
			//	cout<<i<<' '<<h[j]<<'\n';
				int l=a[h[j]-2]+1;
				int r=a[h[j]-1];
				if(l>r)continue;
				sum+=(r-l+1);
				sl=l;
				sr=r;
			}
			hh+=sum;
		}
		cout<<hh<<'\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/