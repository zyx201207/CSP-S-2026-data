#include<bits/stdc++.h>
using namespace std;
long long n,m,sum;
int main()
{
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
queue<int>a;
cin>>a.begin().end();
for(int i=1;i<=n;i++)
{
	sum=0;
	cin>>a[i];
	a.push_back(a[i]);
	for(int j=1;j<=m;j++)
	{
    if(a[i]==m[j])
    a.pop(m[j]);
    else 
    if(a[i]!=m[j])
    a.push_back(a[i]);
    if(m[j]=m)
    sum++;
    }
    cout<<sum;
}
return 0;
}
