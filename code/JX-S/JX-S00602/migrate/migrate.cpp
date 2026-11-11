#include <bits/stdc++.h>
#define PII pair<int,int>
#define int long long
#define OI(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;
const int N=5e5+5;
int T;
int n,d;
int a[N];

int Bfs(int s,int e){
	int sum=0;
	for(int i=1;i<e;sum++){
		bool f=0;
		if(a[i+1]-a[i]>d) return 0;
		for(int j=i+1;j<=e;j++){
			if(a[j]-a[i]>d) f=1,i=j-1;
		}if(f==0)
			if(a[e]-a[i]<=d) i=e;
		
	}
	int ans=0;
	queue<PII> x;
	x.push({s,0});
	while(!x.empty()){
		int v=x.front().first;
		int dd=x.front().second;
		if(v==e&&dd==sum) ans++;
		x.pop();
		for(int i=v+1;i<=e;i++)
			if(a[i]-a[v]<=d) x.push({i,dd+1});
	}
	return ans;
}

signed main(){
	OI("migrate");
	cin>>T>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=3) continue;
		bool fA=1;
		for(int i=1;i<=n-2;i++) 
			if(a[i+1]-a[i]!=a[i+2]-a[i+1]) fA=0;
		if(fA){
			int m=a[2]-a[1];
			if(d!=m*2) cout<<0<<endl;
			else cout<<n-3<<endl;
		}
		else if(n<=10){
			int ans=0;
			for(int s=1;s<=n;s++){
				for(int e=s+1;e<=n;e++){
					ans+=Bfs(s,e);
				}
			}cout<<ans<<endl;
		}
	}
	
	return 0;
}
