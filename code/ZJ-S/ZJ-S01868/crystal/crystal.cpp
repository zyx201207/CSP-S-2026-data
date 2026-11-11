#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N],maxn=1;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		long long o=m;
		long long d=1;
		for(int j=i+1;j<=n;j++){
			o=o-a[i]+a[j];
			d++;
			if(o<0){
				d--;
				break;
			}
		}
		if(d>maxn){
			maxn=d;
		}
	}
	cout<<maxn;
}
