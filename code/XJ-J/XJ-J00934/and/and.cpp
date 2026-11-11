#include<bits/stdc++.h>
using namespace std;
const int N=200001;
int a[N],x[N],t3;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxv=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		int t=a[i],cnt=0;
		x[i]=t%2;
		while(t) {
			t/=2;
			x[i]+=(t%2)*10;
			cnt++;
		}
		int t1,t2;
		for(int y=1,j=1; y<=cnt,j<=cnt; y++,j++) {
			t1=x[y]%10;
			t2=x[j]%10;
			if(t1!=t2) t3=t3*10+0;
			else t3=t3*10+1;
		}
		if(t3>maxv) maxv=t3;
	}
	cout<<maxv;
	return 0;
}