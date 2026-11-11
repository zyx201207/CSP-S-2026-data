#include<bits/stdc++.h>
using namespace std;
int a[20010];
char c[20010];
long long sc=0;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i]>>c[i];
    for(int i=0;i<n;i++)
        for(long long j=0;j<a[i];j++)
            s+=c[i];
    string s1=s;
    reverse(s1.begin(),s1.end());
    string l="",r="";
    if(s==s1) cout<<0;
    else{
        for(long long x=0;x<s.size()/2;x++)
            l+=s[x];
        for(long long y=0;y<s1.size()/2;y++)
            r+=s1[y];
        for(long long j=0;j<l.size();j++)
        {
            if(l[j]!=r[j])
                sc++;
        }
        cout<<sc;
    }
	return 0;
}
