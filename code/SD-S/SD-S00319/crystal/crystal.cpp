#include<iostream>
#include<algorithm>
using namespace std;
int n,l,d;
long long m,s,a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	d=1;
	l=1;
	for(int i=2;i<=n;i++){
		s+=(a[i]-a[i-1])*(i-l);
		while(s>m){
			s-=a[i]-a[l];
			l++;
		}
		d=max(d,i-l+1);
	}
	cout<<d<<'\n';
}
