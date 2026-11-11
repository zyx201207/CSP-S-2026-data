#include<bits/stdc++.h>
using namespace std;
int n,a;
char c;
string s;
long long ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %c",&a,&c);
        for(int j=0;j<a;j++)s+=c;}
    long long p=s.size()/2;
    for(int i=0;i<p;i++)ans+=s[i]!=s[p-i-1];
    printf("%d",ans);
    return 0;
}
