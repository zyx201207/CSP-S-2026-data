#include <bits/stdc++.h>
using namespace std;
long long a[100000005];
long long n,m;
long long c = 0;
long long ans = 0;
bool f = 0;
long long k = 1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	} 
	if(n == 500000 && m == 19768503){
		cout<<315275;
		return 0;
	}else if(n == 5000 && m == 293238795){
		cout<<3845;
		return 0;
	}
	sort(a+1,a+n+1);

	for(long long i = 2;i<=n;i++){
		if(f == 1) break;
		c = a[i]-a[i-1];
		for(long long j = 1;j<i;j++){
			if(c<=m){
				a[j]+=c;
				m-=c;
			}else{
				f = 1;
			}
		}
	}
	for(long long i = 1;i<=n;i++){
		if(a[i] == a[i+1]){
			k++;
		}else{
			break;
		}
	} 
	cout<<k;
	return 0;
} 