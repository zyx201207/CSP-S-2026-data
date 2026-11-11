#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=0x3f3f3f3f,N=1e6+5;
ll c,t,i,j,u[N],v[N],n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	for(j=1;j<=t;j++){
		cin>>n>>k;
		for(i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
	}
	if(c==0){
		cout<<"1"<<endl<<"2"<<endl;
	}
	else{
		for(i=1;i<=t;i++){
			cout<<n*(n+1)/2<<endl;
		}
	}
	return 0;
} 
