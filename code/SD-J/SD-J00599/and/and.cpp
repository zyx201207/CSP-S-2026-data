#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[1000005],e[1000005];
bool f[10005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	cout<<a[1]+a[n];
	return 0;
	//I true not can do that
	//although it may very easily
	//I am a juruo
}

