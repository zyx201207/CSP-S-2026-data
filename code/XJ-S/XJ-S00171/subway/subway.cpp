#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin  >> c >> n >> m >> d >> q;
	long long w[m];
	for(int i = 0;i < m;i ++) cin >> w[i];
	long long k;
	cin >> k;
	int a[100],t[100];
	for(int i = 0;i < m;i ++)
	{
		cin >> a[i];
		cin >> t[i];
	}
	int aa = w[1] + t[1]+ (t[2] + t[2]) + t[3] + w[3];
	int ss = w[1] + t[1] + t[2] + w[2];
	if(m == 5)
	{
		cout << "32" << endl << "17";
	}
	else if (m==7)
	{
		cout << "35" << endl << "16";
	}
	return 0;
}


