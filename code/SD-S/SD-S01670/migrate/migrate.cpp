#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,d,c,T,x[N],gc;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		bool f=1;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i==2){
				gc=x[i]-x[i-1];
			}
			if(f==1&&i>2&&x[i]-x[i-1]!=gc){
				f=0;
			}
		}
		if(f){
			if(d<=gc||d*2>n){
				cout<<"0\n";
			}
			else{
				cout<<n-2*d+1<<"\n";
			}
		}
		else{
			cout<<"0\n";
		}
	}
	return 0;
}  
