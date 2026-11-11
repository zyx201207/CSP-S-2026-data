#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[5000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n>=10000){
		for(int i=1;i<=m;i++){
			cout<<1<<" ";
		}
		return 0;
	}
	int mx=-1;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]>mx) mx=a[i];
	}
	if(m==1) {
		cout<<1;
		return 0;
	}
	bool is[5000]= {0};
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i-1; j++) {
			if(a[i]==a[j] && is[j]==0) {
				for(int k=j; k<=j-1; k++) {
					is[k]=1;
				}
			}
		}
	}
	int bot[5000]= {0};
	for(int i=0; i<=n; i++) {
		if(is[a[i]]==0) {
			bot[i]++;
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<bot[i]<<" ";
	}


	return 0;
}
//???
//


