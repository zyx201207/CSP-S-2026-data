#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],n,m,num=0,b[500005],maxn,maxx;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx>1e6) {
		ll d=a[2]-a[1];
		for(int i=1;i<=1e6;i++) {
			if((1+i)*n*d/2>m) {
				maxn=i-1;//buguanzenmeyang touyidian xingzhi defen
				break;
			}
		}
		cout<<maxn;
		return 0;//duideduide
	}
	sort(a+1,a+1+n);
	b[1]=a[1];
	ll y=1;
	for(int i=2;i<=n;i++) {
		if(a[i]!=b[y]) {
			y+=1;
			b[y]=a[i];
		}
	}
	for(int k=1;k<=y;k++) {
		ll mm=m;
		num=0;
		bool flag=0;
		ll kk=b[k];
		for(int i=n;i>=1;i--) {
			if(a[i]<=kk&&!flag) {
				flag=1;
				kk=a[i];
			}
			if(flag) {
				mm-=kk-a[i];
				if(mm>=0) num+=1;
				else break;
			}
		}
		if(num>maxn) maxn=num;
	}
	cout<<maxn;
	return 0;
}
