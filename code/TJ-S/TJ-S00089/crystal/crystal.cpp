#include<bits/stdc++.h>
using namespace std;
int n,p,q;
long long m,a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		while(a[i]*(i-p)-(s[i]-s[p])>m)p++;
		q=max(q,i-p);
	}
	cout<<q<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
