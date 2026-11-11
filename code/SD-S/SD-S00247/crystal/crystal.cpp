#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],b[N],c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,l=1,an=0;
	long long m,su=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
		c[i]=c[i-1]+b[i];
	}
	for(int r=1;r<n;r++){
		su+=b[r]*(r-l+1);
		while(su>m){
			l++;
			su-=c[r]-c[l-1];
		}
		an=max(an,r-l+1);
	}
	an++;
	cout<<an;
	return 0;
}
