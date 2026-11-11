#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,d,x[3000000],an = 0,fl,be;
ll _check[3000000];

ll _be(ll f,ll b,ll p)
{
	cout << "_be"<<endl;
	cout << "f:"<<f<<" b:"<<b<<" p:"<<p<<endl;
	if(f == b)return p;
	ll _t = _check[f];
	if(_t == 0)return -1;
	if(_t > b)_t = b;
	_be(_t,b,p+1);
}

void _step(ll f,ll b,ll p)
{
	if(f == b)
	{
		if(p == be)
		{
			fl++;
		}
		return;
	}
	if(p == be)return;
	for(int i=1;i<=b-i;i++)
	{
		if(f+i <= _check[f])
		{
			_step(f+i,b,p+1);
		}
		else
		{
			break;
		}
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin >> T >> T;
	while(T--)
	{
		an = 0;
		cin >> n >> d;
		for(int i=1;i<=n;i++)cin >> x[i];
		for(int i=1;i<=n-1;i++)
		{
			for(int j=n;j>=i+1;j--)
			{
				if(x[j] - x[i] <= d)
				{
					_check[i] = j;
					break;
				}
			}
		}
		for(int i=1;i<=n-3;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				be = _be(i,j,0);cout << "i:" << i << " j:" << j <<" be:" << be << endl;
				if(be == -1)break;
				fl = 0;
				_step(i,j,0);
				if(fl == 2)an++;
			}
		}
		cout << an << endl;
	}
	return 0;
}
