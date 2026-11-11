#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],b[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;	
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]){
			flag=false;
		}
	}
	if(flag==true){
		cout<<m;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int x,p;
		bool flag=false;
		for(int j=i;j<=n;j++){
			for(int k=j-1;k>=i;k--){
				if(a[k]==a[j]){
					x=k,p=j-1;
					flag=true;	
				}
			}
		}
		if(flag==true){
			for(int j=i;j<=x;j++){
				b[j]++;
			}
			for(int j=p;j<=n;j++){
				b[j]++;
			}
		}
		else {
			for(int j=i;j<=n;j++){
				b[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
