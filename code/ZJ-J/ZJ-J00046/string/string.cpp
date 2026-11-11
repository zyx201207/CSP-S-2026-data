#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long i,k=1,y,x,cnt=0,ans=0;
	cin>>x;
	struct str
	{
		int it;
		char cr;
		long long se;
	}a[x];
	for(i=0;i<x;i++)
	{
		cin>>a[i].it>>a[i].cr;
		ans+=a[i].it;
		a[i].se=ans;
    }
    for(i=0;i<x;i++)
    if(a[i].se>ans/2){
	y=i;
	break;}
	int n=a[y].it;
	for(i=0;i<y;)
	{
		if(a[i].cr!=a[x-i-k].cr)
		{
		cnt+=min(a[i].it,a[x-i-k].it);
		int z=max(a[i].it,a[x-i-k].it);
		if(z==a[i].it)
		a[i].it-=min(a[i].it,a[x-i-k].it);
		else
		a[x-i-k].it-=min(a[i].it,a[x-i-k].it);
		if(min(a[i].it,a[x-i-k].it)==a[i].it)
		{i++;k--;}
		else{k++;}}
		else i++;
	}
	cout<<cnt;
	return 0;
}