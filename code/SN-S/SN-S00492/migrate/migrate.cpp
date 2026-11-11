//SN-S00492  刘泽   西安铁一中滨河学校 
#include<bits/stdc++.h>
using namespace std;

long long c,t;
long long n,d;
long long site[3];
long long ans;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if((c==11)||(c==12)||(c==0)){
		for(int k=1;k<=t;k++){
			cin>>n>>d;
			for(int i=1;i<=2;i++){
				cin>>site[i];
			}
			for(int i=3;i<=n;i++)cin>>ans;
			int dd=site[2]-site[1];
			if(d<dd*2){
				cout<<0<<endl;
			}
			else if(dd*3<=d){
				cout<<0<<endl;
			}
			else cout<<(n-3)<<endl;
		}
	}
	return 0;
}
