#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
bool flag=true;
int main()
{//freopen("and.in","r",stdin);
//freopen("and.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=0;i<n;i++)
{cin>>a[i];
}
sort(a+0,a+n);
cout<<a[n-m];
return 0;
}
