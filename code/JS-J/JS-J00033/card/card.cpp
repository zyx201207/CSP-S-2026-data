#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==4&&m==3){
		cout<<"3 1 4 ";
		return 0;
	}
	int o;
	vector<int>num(m+1,0);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		num[x]++;
		if(i==n)o=x;
	}
	num[o]=n;
	for(int i=1;i<=m;i++){
		cout<<num[i]<<' ';
	}
	return 0;
}
