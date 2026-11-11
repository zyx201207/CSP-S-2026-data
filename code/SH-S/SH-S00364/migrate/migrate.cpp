#include<iostream>
#include<cmath>
using namespace std;
int c,t;
int a[2000010]={};
int main(){
	freopen("subway.in","r",stdin);
	cin>>c>>t;
	for(int i=1;i<=t;++i){
		int ans=0;
		int m,d;
		cin>>m>>d;
		for(int j=1;j<=m;++j){
			cin>>a[i];
		}
		for(int j=1;i<=m-2;++j){
			for(int k=j+2;k<=m;++k){
				if((a[k]-a[j]>d)&&(a[k]-a[j]<2*d)){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
	freopen("subway.out","w",stdout);
}
