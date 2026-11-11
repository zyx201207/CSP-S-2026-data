#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e6+7;
int a[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,flag1=1,c=-1,now,la;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i!=1){
				if(c==-1) c=a[i]-a[i-1];
				if(c!=a[i]-a[i-1]) flag1=0;
			}
		}
		if(flag1){
			int cnt=d/c;
			if(2*cnt>n||cnt<2) cout<<"0\n";
			else cout<<n-2*cnt+1<<"\n";
		}
	}
	return 0; 
}
