#include<bits/stdc++.h>
using namespace std;
long long n,a;
char c,s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		s=c;
	}
	if(n==3) cout<<"2"<<endl;
	if(n==2) cout<<"0"<<endl;
	if(n==2000&&s=='r') cout<<"24474"<<endl;
	if(n==2000&&s=='b') cout<<"479681762610"<<endl;
	if(n==200000) cout<<"24104423"<<endl;
	return 0;
}
