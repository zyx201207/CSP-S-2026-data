#include<bits/stdc++.h>
using namespace std;
long long n,cd,bt;
string s;
int main()
{
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long a;
        char c;
        cin>>a>>c;
        for(int j=0;j<a;j++) s+=c;
    }
    long long mid=s.size()/2;
    long long l=0,r=s.size()-1;
    for(int i=0;i<mid;i++)
    {
        if(s[l]!=s[r]) bt++;
        l++;
        r--;
    }
    cout<<bt;
	return 0;
}
