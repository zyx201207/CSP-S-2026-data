#include<bits/stdc++.h> 
using namespace std;
int a[1010],w[1010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int y;
		cin>>y;
		for(int j=1;j<=y;j++){
			int s,h;
			cin>>h>>s;
			a[h]=s;
		}	 
	}
	for(int i=1;i<=q;i++){
		int o,t;
		cin>>o>>t;
		int sum=0;
		if(t>o){
			for(int i=o;i<=t;i++){
				if(i==o||i==t){
					sum+=a[i];
				}
				else{
					sum+=2*a[i];
				}
			}
		}
		else{
			for(int i=t;i<=o;i++){
				if(i==o||i==t){
					sum+=a[i];
				}
				else{
					sum+=2*a[i];
				}
			}
		}
		cout<<sum+w[o]+w[t]<<endl;
	}
	return 0;
}