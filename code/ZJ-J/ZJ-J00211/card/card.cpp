#include<bits/stdc++.h>
using namespace std;
int ds[200001],lp[200001];
vector<int>vec;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>ds[i];
		if(ds[i]!=ds[i+1])lp[ds[i]]=1;
	}
	for(int i=1;i<=n;i++){
		cout<<lp[i]<<' ';
	}
	return 0;
}
