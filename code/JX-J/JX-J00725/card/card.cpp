#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],z[300005],num[300005],sum[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int l=1;l<=n;l++){
		int i=l,j=1;
		while(i<=n){
			if(num[a[i]]!=0){
				j=num[a[i]];
				for(int k=num[a[i]];k<=m;k++){num[z[k]]=0;z[k]=0;}
			}
			z[j]=a[i];
			num[a[i]]=j;
			j++;
			i++;
		}
		for(int k=1;k<j;k++)sum[z[k]]++;
		memset(z,0,sizeof(z));
		memset(num,0,sizeof(num));
	}
	for(int i=1;i<=m;i++)
	cout<<sum[i]<<' ';
	return 0;
}
