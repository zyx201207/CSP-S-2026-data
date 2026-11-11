#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500001],b[500001],c[500001];
void sort(int n){
	for(int i=n;i>=1;i--){
		for(int j=1;j<=i-1;j++){
			if(a[j]>a[j+1]){
				int b=a[j];
				a[j]=a[j+1];
				a[j+1]=b;
			}
		}
	}
	
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,qu,tatol;
	int v;
	cin>>n;
	cin>>qu;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(n);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n-1;i++){
		int r=qu;
		v=1;int d=i;
		while(r>0){
			r-=b[d]*v;
			v++;d++;
		}
	if(r<0){
		c[i]=v-1;
	}
	else c[i]=v;
	}
	tatol=c[1];
	for(int i=2;i<n-1;i++){
		if(c[i]>tatol){
			tatol=c[i];
		}
	}
	cout<<tatol;
	return 0;
}
