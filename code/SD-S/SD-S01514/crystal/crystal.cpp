#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];//¿Õ±¯ÇÐ 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int mx=0;
	for(int i=2;i<=n;i++){
		int sum=0;
		int k=a[i];
		for(int j=1;j<i;j++){
			sum+=k-a[j];
		}
		if(sum<=m){
			mx=max(mx,i);
		}
	}
	cout<<mx;
	return 0;
}

