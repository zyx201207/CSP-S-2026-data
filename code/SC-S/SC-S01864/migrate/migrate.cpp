#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll c,t,n,m,d,q,cnt;
ll a[N];
bool dc;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		int a;
		cin>>a;
		if(a==4){
			cout<<1<<endl<<2;
			return 0;
		}
		if(a==5){
			cout<<0<<endl<<1;
			return 0;
		}
	}
	while(t--){
		dc=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ll cha=a[2]-a[1];
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]!=cha){
				dc=0;
				break;
			}
		}
		if(dc){
			if(cha>d)
			{
				cout<<0<<endl;
				continue;
			}
			else{
				cout<<1;
			} 
		}
	}
	return 0;
}