#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int c=a[n/2+1];
	for(int i=n;i>=1;i--){
		if(n/2+1>i){
			for(int j=1;j<=n;j++){
				a[i]++;
				m--;
				if(a[i]==c)
					ans++; continue;
				if(m==0)
					break;
			}
		}
	}
	for(int i=n/2+2;i<=n;i++)
		if(a[i]==c)
			ans++;
	cout<<ans;
	return 0;
}
