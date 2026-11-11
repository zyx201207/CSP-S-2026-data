#include<bits/stdc++.h>

using namespace std;

long long a,s,d,f,g,h,q[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>s;
	
	for(long long z=1;z<=a;z++)
	{
		cin>>q[z];
	}
	sort(q+1,q+a+1);
	for(long long z=1;z<=a;z++)
	{
		if(q[z]==q[z+1])
		continue;
		d=s;
		f=z;
		g=0;
		for(;f>=1;)
		{
			if(q[z]-q[f]<=d)
			{
				d=d-q[z]+q[f];
				g++;
				f--;
			}
			else
			{
				break;
			}
		}
		h=max(h,g);
	}
	cout<<h;
	
	return 0;
} 
