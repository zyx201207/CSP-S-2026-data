#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],s[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	int num=0,sum=0;
	while(num<=m){
		for(int i=1;i<=n;i++){
			for(int j=n;j>=1;j--){
				if(a[i]==a[j]&&a[i]+a[j]<=a[n]){
					s[i]=1;
					s[j]=1;
					num++;
				}
				else if(a[i]+1==a[j]&&a[i]+a[j]<=a[n]){
					s[i]=1;
					s[j]=1;
					a[i]=a[j];
					num++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i]==1){
			sum++;
		}
	} 
	cout<<sum;
	return 0;
} 
