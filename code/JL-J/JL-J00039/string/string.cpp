#include<bits/stdc++.h>
using namespace std;
int n,a[200001],sum;
char c[200001];

int main()
{
freopen("string.in",r,stdin);
freopen("string.out",w,stdout);
ios::sync_with_stdio(o);
cin.tie(0);
cin>>n;
for(int i=1;i<=n;i++)
	cin>>a[i]>>c[i];
for(int i=1;i<=n;i++)
{
if(n-i+1==i)
	break;
if(c[i]==c[n-i+1])
	cout<<"0";
else 
	sum+=a[i];

}
cout<<sum;
return 0;
}
