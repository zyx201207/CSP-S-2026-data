#include<bits/stdc++.h>
struct t{
	long long s;
	char c;
}a[200001];
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,ans=0,minx=0;
	cin >> n;
	long long begin=1,end=n;
	for (long  long i=1;i<=n;++i){
		cin >> a[i].s >> a[i].c; 
	}
	while (begin!=end){
		if (begin>=end){
			break;
		}
		minx=min(a[begin].s,a[end].s);
		if (a[begin].c!=a[end].c) ans+=minx;
		a[begin].s-=minx;
		a[end].s-=minx;
		if (a[begin].s==0){
			begin++;
		}
		if (a[end].s==0){
			end--;
		}
	}
	cout << ans;
	return 0;
} 
