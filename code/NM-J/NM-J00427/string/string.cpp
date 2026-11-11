#include<bits/stdc++.h>
using namespace std;
long long a[200001];
string b;
string x;
string y;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    int s=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i]>>b;
    	for(int j=0;j<a[i];j++)
    	{
    		x=x+b;
		}
	}
	for(int i=x.size();i>0;i--)
	{
		y=x[x.size()-i]+y;
	}
	for(int i=0;i<x.size();i++)
	{
		if(x==y)
		{
			cout<<s;
			return 0;
		}
		else
		{
			x[x.size()-i-1]=x[i];
			y[i]=y[y.size()-i-1];
			s++;
		}
	}
    return 0;
}
