#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+1);
	int b=0,e=1,c=0;
	long long d=1000000000000000000;
	for(int i=1;i<=n;i++){
		c+=a[i];
	}
	c=c/n;
	for(int i=1;i<=n;i++){
		if(a[i]-c<0&&c-a[i]<d||a[i]-c>0&&a[i]-c<d){
			d=a[i]-c;
			e=i;
		}
	}
	while(m){
		if(a[e]==a[e-1]){
			b--;
		}
		else{
			while(a[e]-a[e-1]){
				a[e-1]++;
				m--;
			}
		}
		b++;
		e--;	
	}
	cout<<b;
	return 0;
}
