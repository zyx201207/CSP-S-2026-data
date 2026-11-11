#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
long long ans;
long long c[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >>n >>m;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	sort(c+1,c+1+n,cmp);
	ans=c[1];
	for(int i=2;i<=m;i++){
		ans=ans&c[i];
	}
	cout <<ans;
	return 0;
} 
