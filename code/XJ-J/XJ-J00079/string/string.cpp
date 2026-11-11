#include<bits/stdc++.h>
using namespace std;
long long n,a,cnt=0;
int c;
long long fz(long long c){
	if(c.firt!=c.end)
		cnt++;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n>>a>>c;
	cout<<cnt;
	return 0;
}
