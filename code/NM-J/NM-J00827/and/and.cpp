#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m;
cin>>n>>m;
vector<int> a(n);
for(int i=0;i<n;i++)
{

    cin>>a[i];
}
int a1=1;
sort(a.begin(),a.end(),greater<int>());
for(int i=0;i<n;i++)
{
    a1&=a[i];
}
cout<<a1;
return 0;
}

