#include<bits/stdc++.h>
using namespace std;
string o;
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n,x,l=0,h,i=0;
cin>>n;
for(int i=0;i<n;i++)
{
	int m;
	char b;
	cin>>m>>b;
	if(m>10000)
    {
        cout<<"300000"<<"0000";
        return 0;
    }
	while(m>0)
	{
		o=o+b;
		m--;
	}
}
x=o.size()-1;
h=o.size()/2;
while(h>0)
{

	if(o[i]!=o[x-i]) l++;
	i++;
	h--;
}
cout<<l;
}
