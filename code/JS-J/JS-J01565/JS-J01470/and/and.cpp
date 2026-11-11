#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int k=0,s=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>k){
			k=a[i];
			s=i;
		}
	}
	a[s]=0;
	if(m==1){
		cout<<k;
		return 0;
	}
	int k2=0;
	for(int i=1;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[j]<=k&&a[j]>k2){
				k2=a[j];
				s=j;
			}
		}
		k=k2;
		k2=0;
		a[s]=0;
	}
	cout<<k;
	return 0;
}
