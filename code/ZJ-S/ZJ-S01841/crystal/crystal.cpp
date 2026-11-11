#include<bits/stdc++.h>
using namespace std;
int n,s;
long long m,a[500010],mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long sum=0;
		for(int j=i;j>0;j--){
			sum+=a[i]-a[j];
			if(sum>m){
				mx=max(mx,(long long)i-j);
			}
		}
	}
	cout<<mx;
	return 0;
}