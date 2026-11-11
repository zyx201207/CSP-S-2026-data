#include <bits/stdc++.h>
using namespace std;

struct two{
	long long tw[35],s;
};

struct pei{
	long long o,x;
};

long long a[200005],ab[200005];
two t[200005];
long long y[35];
pei dang[200005];
long long shuai[200005];
long long sk = 0;

bool cmp(pei c,pei d)
{
	return c.o > d.o;	
}

bool cmp1(pei c,pei d)
{
	return c.o < d.o;	
}

int main()
{
    freopen("and.in","r",stdin);                                                 
    freopen("and.out","w",stdout);                                               
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long m = 0,n = 0;
    cin >> n >> m;
    for (long long i = 0;i < n;i++){
    	cin >> a[i];
    	ab[i] = a[i];
	}
	long long mn = 0;
	for (long long i = 0;i < n;i++){
		long long nt = 0;
		while (ab[i]){
			int g = ab[i] & 1LL;
			t[i].tw[nt] = g;
			nt++;
			ab[i] = ab[i] >> 1LL;
		}
		mn = max(mn,nt);
	}
	for (long long i = mn - 1;i >= 0;i--){
		for (long long j = 0;j < n;j++){
			bool ca = 1;
			for (int jj = 0;jj < sk;jj++){
				if(t[j].s == shuai[jj]){
					ca = 0;
					break;
				}
			}
			if (!ca){
				j--;
				n--;
				continue;
			}
			dang[j].o = t[j].tw[i];
			dang[j].x = t[j].s;
		}
		sort(dang,dang + n,cmp);
		if (dang[m - 1].o == 1){
			for (long long j = m - 1;j < n;j++){
				if (!dang[j].o){
					shuai[sk] = dang[j].x;
					sk++;
				}
			}
			y[i] = 1;
		}
	}
	long long po = 0;
	for (long long i = 0;i < mn;i++){
		po += y[i] * pow(1LL * 2,i);
	}
	cout << po;
    return 0;
}
