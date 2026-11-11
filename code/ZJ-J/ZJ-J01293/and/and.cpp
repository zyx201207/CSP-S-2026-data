#include<bits/stdc++.h>
using namespace std;
int q[20020];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long int ans=0;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	sort(q+1,q+1+n,cmp);
	ans = q[1];
	for(int i=2;i<=m;i++){
		ans=ans&q[i];
	}
	cout<<ans;
}
