#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000005];
bool check(long long x,long long y,long long d){
	if(y-x>3)return 0;
	for(int i=x;i<=y;i++){
		if(i>1)if(a[i]-a[i-1]>d)return 0;
		if(i>2)if(a[i]-a[i-2]<d)return 0;
	}
	return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		long long n,d,dx=0,cnt=0,f=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>1)if(dx!=a[i]-a[i-1])f=1;
			dx=a[i]-a[i-1];
		}if(f==1){
			if(dx>=d||3*dx<d)cout<<"0\n";
			else cout<<n-3<<"\n";
			continue;
		}else{
			for(int i=1;i<=n;i++){
				for(int j=i+3;j<=n;j++){
					if(check(i,j,d))cnt++;
				}	
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
} 
