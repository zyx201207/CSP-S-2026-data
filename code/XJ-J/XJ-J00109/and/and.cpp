#include<bits/stdc++.h>
using namespace std;
int b[200002],N,c,a[200002],sum;
int fand(int a,int b) {
	int n=max(a,b),m=min(a,b);
	int ny,my,cnt=0,ans=0;
	while(n!=0) {
		ny=n%2,my=m%2;
		if(ny!=0&&my!=0) ans+=pow(2,cnt);
		cnt++;
		n=n/2,m=m/2;

	}
	return ans;
}
void f(int cnt,int r) {
	if(cnt==c+1) {
		int asum=b[1];
		for(int i=1; i<=c; i++) {
			asum=fand(b[i],asum);
		}
		sum=max(asum,sum);
		return;
	}
	for(int i=r; i<=N; i++) {
		b[cnt]=a[i];
		f(cnt+1,i+1);
	}
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>N>>c;
	for(int i=1; i<=N; i++) {
		cin>>a[i];
	}
	f(1,1);
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
