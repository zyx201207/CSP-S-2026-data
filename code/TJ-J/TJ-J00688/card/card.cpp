#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int mm[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mm[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<mm[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
