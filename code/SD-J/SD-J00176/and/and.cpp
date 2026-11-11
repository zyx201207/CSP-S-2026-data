#include<bits/stdc++.h>
#include<cstdio>
#define int long long
#define endl '\n'
#define Fre
#define Ct

const int N=2e5+10;

using namespace std;

typedef pair<int,int> PII;

int a[N];

bool cmp(int c,int b){
	return c>b;
}

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		int sum=a[i];
		for(int j=i;j<=i+m-1;j++){
			sum&=a[j];
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
}

signed main(){
	
#ifdef Fre
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
#endif

#ifdef Ct
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	int _=1;
	//cin>>_;
	while(_--) solve();
	
	return 0;
}

