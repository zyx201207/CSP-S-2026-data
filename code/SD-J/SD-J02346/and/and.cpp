#include<bits/stdc++.h>
using namespace std;
int a[503305];
bool cmp(int x,int y){return x>=y;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long ans=(1<<60)-1;
	for(int i=1;i<=k;i++) ans&=a[i];
	cout<<ans;            
	return 0;
}
/*
5 3
4 2
3 15 12 12
*/
