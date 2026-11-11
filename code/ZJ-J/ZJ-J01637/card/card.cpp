#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//pian fen(A)
	int n,m;
	int a;
	cin>>n>>m;
	int app[300010];
	for(int i=1;i<=n;i++){
		cin>>a;
		app[a]=i;
	}
	for(int j=1;j<=m;j++){
		cout<<app[j]<<" ";
	}
	cout<<endl;
	//zheng jie
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
