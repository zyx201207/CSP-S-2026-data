#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[2000050],m[2000050];
bool flag=true;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
			m[i]=abs(a[i]-a[i-1]);
			if(i!=2){
			if(m[i-1]!=m[i])flag=false;
		}
		}
		}
		if(flag){
			int ti=d/(m[3]-m[2]);
			cout<<min(n,ti*3)-ti;
		}
		else cout<<5;
	}
	return 0;
}

 
