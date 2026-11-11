#include<bits/stdc++.h>
using namespace std;
bool flag = 1;
long long n,m,num,maxn,sum,l;
long long a[500005];
long long b[500005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				flag = 0;
			}
		}
	}
//	if(flag){
//		int d=1;
//		while(m){
//			m-=d;
//			d++;
//		}
//		cout<<d-1;
//		return 0;
//	}
	if(flag){
		int g=max(a[2]-a[1],a[1]-a[2]);
		int d=1;
		while(m){
			m-=d*g;
			d++;
		}
		cout<<d-1;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=n;i>=1;i--){
		b[n-i+1]=a[i]+b[n-i];
	}
	for(int i=1;i<=n;i++){
		l = n;
		num = n-i+1;
		sum = b[n-i+1];
		while(sum+m<num*a[i]){
			sum -= a[l];
			l--;
			num--;
		}
		maxn = max(num,maxn);
		if(maxn >= n-i+1){
			cout<<maxn;
			return 0;
		}
	}
	cout<<maxn;
	return 0;
}
