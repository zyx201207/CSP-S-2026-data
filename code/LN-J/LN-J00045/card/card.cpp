#include<bits/stdc++.h>
using namespace std;
int n,m,a[500000],b[500000],t=1,ans[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		t=1;
		for(int j=i;j<=n;j++){
			for(int z=1;z<=t;z++){
				if(b[z]==a[j]){
					for(int k=z;k<=t;k++){
						b[k]=0;
					}
					t=z;
					break;
				}
			}
			b[t]=a[j];
			//for(int i=1;i<=t;i++) cout<<b[i]<<' ';
			//cout<<endl;
			t++;
		}
		//cout<<endl;
		//for(int i=1;i<t;i++) cout<<b[i]<<' ';
		//cout<<endl<<endl;
		for(int i=1;i<t;i++){
			if(b[i]<=m) ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
