#include<bits/stdc++.h>
using namespace std;
int n,c,t;
long long d;
bool flaga=true,flagb=false;
long long a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long cha=a[2]-a[1];
		if(d<cha*2){
			cout<<"0"<<'\n';
		}else{
			if(n-(d/cha)*2+1<0){
				cout<<"0"<<'\n';
			}else{
				cout<<n-(d/cha)*2+1<<'\n';
			}
		}
	}
	return 0;
}
