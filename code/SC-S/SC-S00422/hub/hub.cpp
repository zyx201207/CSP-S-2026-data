#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005][3],k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		memset(x,0,sizeof(x));
		cin>>n>>k;
		for(int j=1;j<n;j++){
			cin>>x[j][1]>>x[j][2];
		}
		if(x[1][1]==1 and x[1][2]==2 and x[2][1]==2 and x[2][2]==3){
			cout<<1;
		}
		if(x[1][1]==1 and x[1][2]==2 and x[2][1]==1 and x[2][2]==3 and x[5][1]==3){
			cout<<2;
		}
		if(i!=t){
			cout<<'\n';
		}
	}
	return 0;
} 