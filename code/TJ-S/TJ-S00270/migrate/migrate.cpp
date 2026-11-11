#include<bits/stdc++.h>
using namespace std;

long long c,t,n,d,cnt,cha,flag=1;
long long x[2000005];

void solve(){
	cin>>n>>d;
	cnt=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(i==1) continue;
		if(i==2) cha=x[i]-x[i-1];
		else if(x[i]-x[i-1]!=cha) flag=0;
	}
	if(flag==1){
		cout<<0<<"\n";
		return ;
	}
	if(x[n]-x[1]<=10*d){
		cout<<1<<"\n";
		return ;
	}
	if(x[1]+d>=(x[1]+x[n])/2){
		cout<<0<<"\n";
		return ;
	}
	for(int i=n;i>=1;i--){
		for(int j=i-1;j>=1;j--){
			if(x[i]-x[j]%d==0) cnt++;
		}
	}
	cout<<cnt<<"\n";
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>t;
	while(t--){
		solve();
	}
	
	return 0;
} 
