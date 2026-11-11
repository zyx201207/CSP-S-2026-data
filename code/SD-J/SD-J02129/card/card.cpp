#include<bits/stdc++.h>
using namespace std;
int a[500005],s[500005],d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flag=0;
		d[a[i]]=i;
	}
	if(flag){
		for(int i=1;i<=n;i++) cout<<d[i]<<' ';
	}
	else{
		for(int i=1;i<=n;i++) cout<<i<<' ';
	}
	return 0;
}
