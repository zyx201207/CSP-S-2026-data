#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],s[500010];
int num[500010],sum[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int r=i;
		while(r<=n){
			sum[a[r]]=1;
			r=s[a[r]]+1;
		}
		for(int j=1;j<=m;j++){
			num[j]+=sum[j];
			sum[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<num[i]<<' ';
	return 0;
}