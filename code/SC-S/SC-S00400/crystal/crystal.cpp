#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f[500005],d[500005],maxn,num,p,q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>> n >> m;
	for(int i = 1;i<= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		if(a[i]<a[i-1] && i-1!=0){
			p=a[i];
			a[i-1] = a[i];
			a[i] = p;
			i=1;
		}
	}
	for(int i = 1;i<= n;i++){
		d[i] = a[i];
		for(int j = 1;j<=i;j++){
			if(d[i]==d[j]){
				num++;
			}
			else if(q >= d[i]-d[j]){
				q-=d[i]-d[j];
				d[j] == d[i];
				num++;
			}
		}
		q = m;
		maxn = max(num,maxn);
		num = 0;
		d[i] = a[i];
	}
	cout << maxn;
	return 0;
} 
