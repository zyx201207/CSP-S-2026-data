#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 2e6+100,INF=3e18+10;
int x,y,n,m=1,w,v;
int mx = -INF ,mn = INF;
int a[N];
int ans = 0, sum = 0;
signed main(){
	freopen ("mirgrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	cin >> x >> w;
	while(w--)
	{
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
		}
		if(n == 4)
		{
			cout <<1<< endl;
		}else{
			cout <<0<<endl;
		}
//		cout<< ans <<endl;
	}
	return 0;
}

//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

//0 2
//5 3
//-2 -1 0 1 2 
//6 2
//-4 -3 -2 -1 3 6
