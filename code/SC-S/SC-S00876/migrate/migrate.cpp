#include<bits/stdc++.h>
#define N 2000005
using namespace std;
int c,t,n;long long d,x[N];
void work(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	if(n==1){cout<<0<<"\n";return;}
	long long bc=d/(x[2]-x[1]);
	if(bc==0||bc==1)cout<<0<<"\n";
	else cout<<max(n-2*bc+1,0ll)<<"\n";
}int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>t;
	while(t--)work();
	return 0; 
}