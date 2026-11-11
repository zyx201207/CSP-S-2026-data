#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500001],x[500001],ans=1,s=1,spend=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		x[i]=a[i+1]-a[i];
	}
	int j=1;
	for(int i=1;i<=n;i++){
		s--;
		while(spend<=m&&j<=n){
			s++;
			spend+=x[j]*s;
			j++;
		}
		if(s>ans){
			ans=s;
		}
		spend=spend-a[j]+a[i];
	}
	cout<<ans;
	return 0;
} 
