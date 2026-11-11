#include<bits/stdc++.h>
using namespace std;
int a[10000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n/2+1;i++){
		if(a[n/2+1]-a[i]+ans<=m){
			ans+=a[n/2+1]-a[i];
		}
		else{
			break;
		}
		sum++;
	}
	for(int i=n/2+2;i<=n;i++){
		if(a[i]==a[n/2+1]){
			sum++;
		}
	}
	cout << sum;
	return 0;
}