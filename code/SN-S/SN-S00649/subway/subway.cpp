#include<bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n;
	cin >> n;
	long long m=4531231275684321;
	if(n<=10) cout << 37 << endl << 16;
	else if(n<= 100) for(int i = 1;i <= m%5+1;i++) cout << m%100,m/=10;
	else if(n<= 10000) for(int i = 1;i <= m%10+1;i++) cout << m%15,m/=10;
	else if(n<= 100) for(int i = 1;i <= m%50+1;i++) cout << m%100,m/=15;
	else for(int i = 1;i <= m%100+1;i++) cout << m%100,m/=17;
	return 0;
}
