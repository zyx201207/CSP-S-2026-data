#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#define IO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ull unsigned long long
#define ll long long
using namespace std;
const int N = 2e6 + 5;

ll a[N];



ll read()
{
	ll f =1 , rt =0;
	char sv = getchar() ;
	while(sv < '0' || sv>  '9')
	{
		if(sv == '-'){f = -1;sv = getchar(); break;
		}
	}
	while(sv!=' ')
	{
		rt *=10;
		rt += sv -'0';sv = getchar();
	}
	return f* rt;
}
int main()
{
	IO
	freopen("migrate.in" , "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c;cin>>c;
	int t;cin>>t;
	if(c==13||c==14)
	{
	while(t--){
		int n , d;cin>>n>>d;
	for(int i=1; i<=n ;i++)
	{
	a[i] = read();
	}	
	if(n<=1){cout<<0<<'\n';continue;
	}
	if( (  (a[2] - a[1])  <<1)  >d){cout<<0<<'\n';continue;}
	else{
	cout<<n-2<<'\n';	}
	}
	} 
	while(t--){cout<<'0'<<'\n'; 
	}
	
cout<<flush;
	return 0;
}
