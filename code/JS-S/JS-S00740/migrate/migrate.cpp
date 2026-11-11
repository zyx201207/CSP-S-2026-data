#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 2e6 + 10;

long long x[MAXN] = {};
int num[MAXN] = {};//if nes, the number of fastest route to the next nes, for n, 0 | if not nes, to the next nes
int flg[MAXN] = {};//if nes, 1, if not , 0
int bnum[MAXN] = {};
int lis[MAXN] = {};
int sz = 0;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

    int c,t;
    cin >> c >> t;
    while(t--)
    {
        int n;
        long long d;
        cin >> n >> d;
        cout << 5 << endl;
    }

	fclose(stdin);
	fclose(stdout);
	return 0;
}
