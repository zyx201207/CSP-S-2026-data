#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],sum[500010],ma,p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	while(n--){
	p++;
	cin>>a[p];
	for(int i=p;i<=n;i++){
		b[i]=a[i];
		for(int j=1;j<=i-1;j++)
			if(b[j]==a[i])
				for(int k=i-j+1;k<=n;k++){
					b[k]==0;
				}
	}
	for(int i=1;i<=n;i++)
		sum[b[i]]++;
	for(int i=1;i<=500010;i++){
		a[i]=0;
		b[i]=0;
	}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}