#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//I can only do this...cheat some score...w^w
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll sum=a[1];
	for(int i=2;i<=m;i++){
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}
