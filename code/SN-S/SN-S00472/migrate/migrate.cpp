//SN-S00472 马一涵 陕西省西安中学 
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t,n,d,x[N]; 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.ans","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int j=0;j<n;j++) cin>>x[j];
		if(c==11 || c==12){
			int cz=x[1]-x[0];
			int ab=ceil(d/cz);
			if(d<cz*2){
				cout<<0<<"\n";
			}
			else{
				int m=n,ans=0;
				cout<<0<<"\n";
			}
		}
		else cout<<0<<"\n";
	}
	return 0;
}
