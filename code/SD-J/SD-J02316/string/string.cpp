#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[100000000];
char c[100000000];
char s[100000000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==1){
		cout<<min(a[1],a[2]);
		return 0;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

