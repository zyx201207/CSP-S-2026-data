#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,q,ans,cha,fc,a[10000005],nn;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cha=a[2]-a[1];
		fc=1;
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=cha){
				fc=0;
				nn=n-2;
				break;
			}
		}
		//cout<<nn<<endl;
		if(fc){
			//nn=n;
			if(d==cha*2){
				cout<<n-3<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
		else{
			if(nn-3>0&&d==cha*2){
				cout<<nn-3;
			}	
			else{
				cout<<0;
			}
			cout<<endl;
		}
	}
	
	return 0;
}
