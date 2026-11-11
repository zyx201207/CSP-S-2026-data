#include<iostream>
using namespace std;
long long n,m,a[510000],ans[310000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int flag;
		for(int j=i;j<=n;j++){
			flag=a[j];
			bool ok=true;
			for(int k=j+1;k<=n;k++){
				if(flag==a[k]){
					j=k-1;
					ok=false;
					break;
				}
			}
			if(ok){
				ans[flag]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}
