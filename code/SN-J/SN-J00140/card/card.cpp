#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[50005],b[50005],x[30005]={0};
	cin>>n>>m;//m:种类，n:局数 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		x[a[i]]++;
	}
	x[a[0]]+=1;
	x[a[n-1]]=n;
	for(int i=1;i<=m;i++){
		cout<<x[i]<<" ";
	}
	return 0;
}
