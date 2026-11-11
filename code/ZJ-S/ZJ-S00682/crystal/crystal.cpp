#include<bits/stdc++.h>
using namespace std;
long long n,m,sum = 0,xum = 0,zum = 0;
long long a[500005];
bool AC(long long x){
	long long num = 0,f = x;
	for(long long j = 1;j <= x;j++){
		num += (a[f] - a[j]);
		if(num > m) return 0;
	}if(num <= m) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i = 1;i <= n;i++) cin>>a[i];
	sort(a + 1,a + n + 1);	
	for(long long i = n;i >= 1;i--){
		zum++;
		if(AC(i)){
			cout<<i;
			return 0;
		}
	}
	return 0;
}