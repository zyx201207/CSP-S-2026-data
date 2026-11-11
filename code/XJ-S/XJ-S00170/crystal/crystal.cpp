#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b[N];
int num,j;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]-a[1]>m) continue;
		for(j=1;j<i&&b[i]<=m;j++) b[i]+=a[i]-a[j];
		num=max(j,num);
	}
	cout<<num;
	return 0;
} 
