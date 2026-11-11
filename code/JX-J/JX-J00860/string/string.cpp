#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char b[200001];
char c[100000001];
int main()
{
  freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
int n,i,j;
cin>>n;
for(i=1;i<=n;++i)
{
    cin>>a[i]>>b[i];
}
bool uu=true;
for(int j=1;j<=n;++j)
{
    if(b[j]!=b[1])
        uu=false;
}
if(uu)
{
    cout<<0<<endl;
    return 0;
}
long long ss=0;
for( j=1;j<=n;++j)
{
    for(int l=1;l<=a[j];++l)
    {ss++;
        c[ss]=b[j];

    }
}
long long sss=0;
for(j=1;j<=ss/2;++j)
{
    if(c[j]!=c[ss-j+1])
        sss++;
}
cout<<sss<<endl;
return 0;
}
