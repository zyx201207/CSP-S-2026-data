#include <bits/stdc++.h>
using namespace std;

int cntb[35];
struct node
{
	int n;
	bool bt[35];
};
vector <node> a;
vector <node> b;
bool f[40];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 34; j++)
			f[j] = 0;
		int sc, cnt = 1;
		scanf("%d", &sc);
		node p;
		p.n = sc;
		while (sc)
		{
			f[cnt] = sc % 2;
			sc /= 2;
			cnt++;
		}
		for (int j = 1; j <= 34; j++)
			p.bt[j] = f[j];
		a.push_back(p);
		for (int j = 1; j <= 34; j++)
			cntb[j] += f[j];
	}
	
	
	
	
	
	int ans = 0, st = 35, cntn = n;
	while(st >= 1)
	{
		n = cntn;
		b.clear();
		for (int i = 0; i < n; i++)
			b.push_back(a[i]);
		a.clear();
		st--;
		
		
		bool flg = 0;
		for ( ; st >= 1; st--)
			if (cntb[st] >= m) 
			{
				flg = 1;
				break;
			}
		if (!flg)
		{
			printf("%d\n", ans);
			return 0;
		}
		int k = (int)pow(2, st - 1);
		ans += k;
		cntn = 0;
		for (int j = 1; j <= 34; j++)
			cntb[j] = 0;
		
		
		for (int i = 0; i < n; i++)
		{
			if (b[i].bt[st])
			{
				a.push_back(b[i]);
				for (int j = 1; j <= 34; j++)
					cntb[j] += b[i].bt[j];
				cntn++;
			}
		}
	}
	cout << "ans\n";
	return 0;
}
