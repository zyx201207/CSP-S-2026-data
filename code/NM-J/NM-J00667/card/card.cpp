
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	int a[500010],b[500010];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			for(int k=i;k<=j;k++){
				if(b[j]==a[k]){
					for(int l=j;l>=k;l--)b[l]=0;
					j=k;
				}
			}
		}
		for(int j=1;j<=n-m;j++){
			if(b[j]==i){
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
