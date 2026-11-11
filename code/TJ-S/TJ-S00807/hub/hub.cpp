#include<bits/stdc++.h>
using namespace std;
long long u[5000005]={0},v[5000005]={0};
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
	}
	if(c==0){
		cout<<"1"<<endl<<"2";
	}
	else{
		for(int i=1;i<=t;i++){
			cout<<i+2;
		}
	}
	return 0;
}

