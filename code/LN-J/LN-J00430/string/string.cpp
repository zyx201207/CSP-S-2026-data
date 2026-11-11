#include<bits/stdc++.h>
using namespace std;
int f(string x)
{
    string y=x;
    x=reverse(x.begin(),x.end);
    if(x==y)return 1;
    else return 0;
}
int main()
{
    string s;
    long long n,a;
    char b;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        for(int i=0;i<a;i++)s+=b;
    }
    if(f(s))cout<<0;
	return 0;
}
