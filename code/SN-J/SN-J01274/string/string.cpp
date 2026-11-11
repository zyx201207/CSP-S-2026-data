#include<bits/stdc++.h>
using namespace std;
struct S{
	long long s;
	char c;
};
S a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i].s>>a[i].c;
	int i=0,j=n-1;
	while(a[i].s!=0){
		int mi=min(a[i].s,a[j].s);
		if(a[i].c!=a[j].c)ans+=mi;
		a[i].s-=mi;
		a[j].s-=mi;
		if(a[j].s==0)j--;
		if(a[i].s==0)i++;
	}
	cout<<ans;
	return 0;
}
