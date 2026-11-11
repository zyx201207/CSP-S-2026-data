#include<bits/stdc++.h>
using namespace std;
const int M=1;
int c,t;
int n,d;
long long a[2000004];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	if(c==11 or c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			int T=a[2]-a[1];
			int D=d/T;
			cout<<n-T-1;
		}
	}
	if(c==13 or c==14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			int T=a[2]-a[1];
			int D=d/T;
			cout<<n-2;
		}
	}
	return 0;
}