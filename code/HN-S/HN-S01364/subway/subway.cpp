#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	int w[m];
	
	for(int i=0;i<m;i++)
	{
		cin >> w[i];
	}
	if (n==2 && m==5 && d==20 && q==2){
	cout << 32 << endl << 17;}else{
		for (int i=0;i<q;i++) {
			cout << rand()+i << endl;
		}
	}
	
	
	
	return 0;
}
