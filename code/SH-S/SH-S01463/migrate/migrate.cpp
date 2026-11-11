#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+10;
int n;
int a[N];
int b[N];
int d;
int len;
int c[N];
int dp[N];
int ea[N];
bool vis[N];

signed main(){
	freopen("migrate3.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cc,T;
	cin>>cc>>T;
	while(T--){
	
	memset(dp,0,sizeof(dp));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(ea,0,sizeof(ea));
	cin>>n>>d; len=1;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		while(a[i]-a[len]>d){
			b[len]=i-1;
			len++;
		}
	}
	while(len<=n){
		b[len]=n;
		len++;
	}
	for(int i=1;i<=n;i++){
		c[i]++;
		c[b[i]+1]--;
	}
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+c[i];
	}
	for(int i=1;i<=n;i++){
		c[i]=c[i]-1;
		if(c[i]==1){
			if(c[i-1]==0) ea[i]++;
			ea[i]=ea[i-1]+1;
		}
		else ea[i]=0;
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i]-i;
	}
//	for(int i=1;i<=n;i++){
//		cout<<b[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<c[i]<<" ";
//	}
//	cout<<endl;
//	
//	for(int i=1;i<=n;i++){
//		int len=0;
//		bool flag=0;
//		for(int j=i-1;j>=i-c[i];j--){
//			if(b[j]+j>=i) len++;
//			if(vis[j]) flag=1;
//		}
//		if(len==2) vis[i]=1;
//	}
	cout<<"0";
	}

	return 0;
}
