#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
long long pre[N];
long long qz[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	bool flag=true;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=i;
		if (a[i]!=i){
			flag=false;
		}
	}
	if (flag==true){
		for (int i=1;i<=INT_MAX;i++){
			if (m<pre[i]){
				cout<<i;
				return 0;
			}
			m-=pre[i];
		}
	}
	long long cha=a[2]-a[1];
	long long need=m/cha;
	for (int i=1;i<=INT_MAX;i++){
		pre[i]=pre[i-1]+i;
		if (pre[i]>need){
			cout<<i;
			return 0;
		}
	}
	return 0;
}//rp++
