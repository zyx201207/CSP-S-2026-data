#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],maxn=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		for(int i=1;i<n;i++)
			a[i]=a[i]&a[i-1];
		cout<<a[n-1];
		return 0;
	}
	maxn=0;
	if(m==2){
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				maxn=max(maxn,a[i]&a[j]);
		cout<<maxn;
	}
}