#include<bits/stdc++.h>
using namespace std;
long long c,t,n,k,v[5000005],u[5000005],da;
int main(){
freopen("hub.in","r",stdin);
freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
	cin>>n>>k;
	for(int j=1;j<n;j++)
	cin>>u[j]>>v[j];
	da=(n-1)/2+3;
	if((da-k)%4==0)
	cout<<(da-k)/4<<endl;
	else
	cout<<(da-k)/4+1<<endl;
	}
	return 0;
}
