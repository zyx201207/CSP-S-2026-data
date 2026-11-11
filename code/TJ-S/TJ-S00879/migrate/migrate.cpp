#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long bianhao,zs,l,ds,d[10000];
	cin>>bianhao>>zs;
	if(bianhao==11||bianhao==12){
		for(int i=1;i<=zs;i++){
			cin>>ds>>l;
			for(int j=1;j<=ds;j++){
				cin>>d[i];
			}
			long long k=d[2]-d[1];
			if(l>=2*k&&l<3*k){
				cout<<ds-3<<'\n';
			}else{
				cout<<0<<'\n';
			}
		}
	}
	else{
		for(int i=1;i<=zs;i++){
			int pp=0;
			cin>>ds>>l;
			for(int j=1;j<=ds;j++){
				cin>>d[j];
			}	
			for(int j=1;j+3<=ds;j++){
				if(l>=d[j+2]-d[j]&&l>=d[j+3]-d[j+1]&&l<d[j+3]-d[j]){
					pp++;
				}
			}
			cout<<pp<<'\n';
		}
	}
	return 0;
}
