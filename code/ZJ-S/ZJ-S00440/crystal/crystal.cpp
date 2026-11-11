#include<bits/stdc++.h>
using namespace std;
const int N=5e5 +5;
long long x,an,n,m,c[N],s[N],a[N],l,r,mi;
bool ch(long long y,int z){
	if(s[z]-s[y-1]-(y-1)*(a[z]-a[y])<=m) return 1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		s[i]=s[i-1]+c[i]*(i-1);
	}
//	for(int i=2;i<=n;i++){
//		cout<<c[i]<<' '<<s[i]<<'\n';
//	}
	for(int i=1;i<=n;i++){
		l=1;
		r=i;
		while(l<=r){
			mi=(l+r)/2;
//			cout<<mi<<' '<<i<<' '<<s[i]-s[mi]-(mi-1)*(a[i]-a[mi])<<'\n';
			if(ch(mi,i)){
//				cout<<i<<' '<<mi<<'\n';
				r=mi-1;
				x=i-mi+1;
			}
			else l=mi+1;
		}
//		cout<<x<<'\n';
		an=max(an,x);
	}
	cout<<an;
	return 0;
}
