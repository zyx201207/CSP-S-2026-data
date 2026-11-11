#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10000],b[10000];
	for (int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i+1;j>=1;j--){
			if (a[i]==a[j])
			{
				for (int k=j;k<i;k++){
					b[j]=0;
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
