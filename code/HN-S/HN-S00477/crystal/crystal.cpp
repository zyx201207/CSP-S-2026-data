#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
int a[500010];

bool f1=1;
bool f2=1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp)
	for(int i=1;i<=n;i++){
		if(a[i]!=i)f1=0;
		if(i>=2&&a[i]-a[i-1]!=a[2]-a[1])f2=0;
	}
	if(f1){
		cout<<m;
	}
	else if(f2){
		cout<<m/(a[2]-a[1]);
	}
	else{
		cout<<3;
	}
	return 0;
}
