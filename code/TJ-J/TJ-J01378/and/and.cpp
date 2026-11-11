#include<bits/stdc++.h>
using namespace std;
int n,a[200001],ma=-1,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int q=0;
		for(int j=i+1;j<=i+m;j++){
			q=a[j-1]&a[j];
		}
		if(q>ma)ma=q;
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
