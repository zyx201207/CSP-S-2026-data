#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
string b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++)
		{
			s=s+b[i]; 
		}
	}
    int l=0,r=s.size()-1;
    int ant=0;
    while(l<r)
    {
        if(s[l]!=s[r]) ant++;
        l++;
        r--;
	}
	cout<<ant;
   	return 0;
}
