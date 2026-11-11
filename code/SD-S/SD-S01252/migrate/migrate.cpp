#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,T;
int n,d,nd;
int a[N];
int solve1(int n,int d,int nd){
	if(d<2*nd) return 0;
	int cnt=d/nd;
	return n-(cnt*2-1);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		bool f=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==1) continue;
			else if(i==2) nd=a[i]-a[i-1];
			else if(a[i]-a[i-1]!=nd) f=1;
		}
		if(f==0){
			cout<<solve1(n,d,nd)<<"\n";
			continue;
		}
		if(d>=a[n]-a[1]){
			cout<<"0\n";
			continue;
		}
		if(n<=3){
			cout<<0<<"\n";
			continue;
		} 
		if(n==4){
			if(a[4]-a[1]<d&&a[3]-a[1]>=d&&a[4]-a[2]>=d){
				cout<<1<<"\n";
			}else{
				cout<<0<<"\n";
			}
			continue;
		}
	}
	
	return 0;
}
