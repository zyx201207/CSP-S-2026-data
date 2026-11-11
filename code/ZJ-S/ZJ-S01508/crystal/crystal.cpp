#include<bits/stdc++.h>
using namespace std;
int n,p,k=1;
long long a[500005],c[500005],m,x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int b;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==1){
			b=a[1]-a[0];
		}
		if(i>0 && b!=a[i]-a[i-1]){
			k=0;	
		}
	}
	sort(a,a+n);
    long long yy=a[0];
	if(k){
		long long sum;
		if(n%2==1){
			sum=(n/2)*(b*(n/2+1));
		}else{
			sum=(n/2)*b*(n/2-1)+n/2*b;
		}
		if(sum<=m){
			cout<<n;
		}
		int g=0;
		for(int i=1;i<=n/2-(n%2==0);i++){
			g+=i*b*2;
			if(g==m){
				cout<<i*2+n;
				return 0;
			}
			if(g>m){
				if(g=-i*b<=m){
					cout<<i*2-1+n;
				}else{
					cout<<i*2-2+n;
				}
				return 0;
			}
		}
		cout<<n-1;
		return 0;
	}
	for(int i=0;i<n;i++){
		x=0;
		for(int j=0;j<i;j++){
			c[j]=a[i]-a[j];
			x+=c[j];
		}
		for(int j=i+1;j<n;j++){
			c[j]=a[j]-a[i];
		}
		sort(c,c+n);
		int g=m,s=0;
		for(int j=1;j<n;j++){
			if(c[j]>g){
				p=max(p,s);
				continue;
			}else{
				g-=c[j];
				s++;
			}	
		}
		p=max(s,p);
	}
	cout<<p+1;
	return 0;
}