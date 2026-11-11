#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sj,k;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>sj>>k;
	if(sj==11||sj==12){
		while(k--){
			int n,d,ch;
			cin>>n>>d;
			map <int ,ll> a;
			for(ll i=0;i<n;i++){
				cin>>a[i];
			}
			ch=a[1]-a[0];
			if(d>a[n/2]-a[0]){
				ll k=((a[n-1]-a[0])-d)/ch;
				cout<<k<<"\n";
				continue;
			}
			cout<<0<<"\n";
		}	
	}
	
	return 0;
}



