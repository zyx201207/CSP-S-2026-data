#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],num,sum,o,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	num=m;
	sort(b+1,b+n+1);
	for(int i=n;i>=1;i--){
		for(int w=1;w<=n;w++){
			a[w]=b[w];
		}
		for(int j=i-1;j>=1;j--){
			if(a[i]!=a[j]&&a[i]-a[j]<=m&&m>0){
				m-=(a[i]-a[j]);
				a[j]=a[i];
			}
		}
		for(int k=n;k>=1;k--){
			if(a[k]==a[i]){
				ans++;
			}
		}
		if(o<ans){
			o=ans;
		}
		ans=0;
		for(int w=1;w<=n;w++){
			a[w]=b[w];
		}
		m=num;
	}
	cout<<o;
	return 0;
} 
