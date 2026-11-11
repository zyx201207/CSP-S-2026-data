#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long b[500010];
long long c[500010];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	c[1]=0;
	for(int i=2;i<=n;i++){
		c[i]=b[i-1]*(i-1);
	}
	int l=1,r=1,mx=0,num=1,xq=0;
	while(r<=n){
		r++;
		num++;
		xq+=(a[r]-a[r-1])*(r-l);
		while(xq>m){
			xq-=a[r]-a[l];
			l++;
			num--;
		}
		if(num>mx){
			mx=num;
		}
	}
	cout<<mx;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
 
