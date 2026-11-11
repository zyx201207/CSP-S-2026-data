#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
void f(int x){
	a[x]=1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]==a[n]){
		cout<<n;
		return 0;
	}
	cout<<n-1;
	return 0;
};
