#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[400010];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
cin >>n>>m;
for(int i=1;i<=n;i++)
{
	cin >>a[i];
}
sort(a+1,a+n+1);
reverse(a+1,a+n+1);
long long t=a[1];
cout <<a[m];
	
	return 0;
}
