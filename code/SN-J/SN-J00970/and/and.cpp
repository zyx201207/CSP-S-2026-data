#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200010]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int num=0;
	int z=0;
	for(int i=1;i<=m;i++){
		int maxn=0;
		for(int j=1;j<=n;j++){
			if(a[j]>maxn){
				maxn=a[j];
				z=j;
			}
		}
		if(i==1){
			num=maxn;
		}
		a[z]=0;
		num=num&maxn;
	}
	cout<<num;
	return 0;
}
