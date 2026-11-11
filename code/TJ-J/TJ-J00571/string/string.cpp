#include<bits/stdc++.h>
using namespace std;
int n,len;
int l=1,r;
long long ans;
vector<long long> a;
vector<char> c;
long long ax;
char cx;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	len=n;
	a.push_back(0);
	c.push_back('0');
	for (int i=1;i<=n;i++){
		long long ay;char cy;
		cin>>ay>>cy;
		a.push_back(ay);c.push_back(cy);
		if (c[i]==c[i-1]){
			ax=a[i]+a[i-1];cx=c[i];
			a.pop_back();a.pop_back();c.pop_back();c.pop_back();
			a.push_back(ax);c.push_back(cx);
			len--;
		}
	}
//	cout<<endl;
//	for (int i=1;i<=len;i++) cout<<a[i]<<' ';
//	cout<<endl;
//	for (int i=1;i<=len;i++) cout<<c[i]<<' ';
//	cout<<endl;
	r=len;
	while (l<=r){
//		cout<<a[l]<<' '<<c[l]<<"  "<<a[r]<<' '<<c[r]<<'\n'<<l<<' '<<r<<"\n\n";
		if (a[l]==a[r] && c[l]!=c[r]){
			ans+=a[r];
			l++;
			r--;
			continue;
		}
		if (a[l]>a[r] && c[l]!=c[r]){
			ans+=a[r];
			a.insert(a.begin()+l+1,a[l]-a[r]);
			c.insert(c.begin()+l+1,c[l]);
			l++;
			continue;
		}
		if (a[l]<a[r] && c[l]!=c[r]){
			ans+=a[l];
			a.insert(a.begin()+r,a[r]-a[l]);
			c.insert(c.begin()+r,c[r]);
			l++;
			continue;
		}
		l++;
		r--;
	}
//	for (int i=1;i<=len+1;i++) cout<<a[i]<<' ';
//	cout<<endl;
//	for (int i=1;i<=len+1;i++) cout<<c[i]<<' ';
//	cout<<endl;
	cout<<ans;
	return 0;
}
