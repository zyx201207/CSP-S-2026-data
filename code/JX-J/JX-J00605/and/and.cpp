#include<bits/stdc++.h>
using namespace std;
int a,s,d,f[10000001];
int main()
{
	
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>a>>s;
for(int i=0;i<a;i++){
cin>>f[i];
}
sort(f,f+a-1);
cout<<f[a-1];
return 0;
}
