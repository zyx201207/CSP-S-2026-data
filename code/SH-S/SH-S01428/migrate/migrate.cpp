#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000005];
void solve1(){
	memset(x,0,sizeof(x));
	int ans=0;
	cin>>n>>d;
	int temp;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	d=float(d/(x[2]-x[1]));
	temp=2*d-1;
	if(temp<=1){
		cout<<0<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(i+temp<=n)ans++;
	}
	
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		
			solve1();
		
	}
	
	
	return 0;
}
