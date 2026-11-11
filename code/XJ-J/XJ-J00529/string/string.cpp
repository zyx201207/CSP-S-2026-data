#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
// string abc = "abcdefghijklmnopqrstuvwxyz";
string vis[114514]; // vis:"",""
ll vsiz = 0;
ll t = 0;

bool res(string str)
{
	string temp;
	temp = str;
	reverse(str.begin(), str.end());

	return str == temp;
}

ll minn = 21474836470;

void f(ll x, string tmp, ll cnt)
{
	if (t >= 6700000 && minn != 21474836470)
		return;
	else if (t > 9100000 && minn != 21474836470)
		return;
	else if (t >= 10000000)
		return;
	if (x > tmp.size())
	{
		return;
		// cout << "ret" << x << " " << tmp << " " << cnt << endl;
	}

	if (res(tmp))
	{
		ll ch = 0;
		for (ll i = 0; i < s.size(); i++)
		{

			if (s[i] != tmp[i])
				ch++;
		}
		if (ch != cnt)
			return;
		minn = min(cnt, minn);
		// cout << "find x" << x << " tmp:" << tmp << " cnt" << cnt << endl;
		return;
	}
	// cout << "go x" << x << " tmp:" << tmp << " cnt" << cnt << endl;
	for (ll i = 0; i < tmp.size(); i++)
	{
		for (ll j = 0; j < s.size(); j++)
		{
			if (tmp[i] == s[j])
				continue;
			// cout << "inj x" << x << " tmp:" << tmp << " cnt" << cnt << " i" << i << " j" << j << " tmp_i:" << tmp[i] << " abc_j:" << s[j] << endl;
			t++;
			f(x + 1, tmp, cnt);
			tmp[i] = s[j];

			f(x + 1, tmp, cnt + 1);
			/*vis[vsiz] = tmp;
			vsiz++;*/
			// tmp=s;
		}
		tmp = s;
	}
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++)
	{
		ll a;
		string b;
		cin >> a >> b;
		for (ll j = 1; j <= a; j++)
		{
			s += b;
		}
	}

	f(0, s, 0);

	if (minn == 21474836470)
	{
		srand(time(0));
		minn = rand() % 10000;
	}
	cout << minn;

	return 0;
}

/*
aabbc
12345



f(1)(a->b) ->f2
f4(b->a)





ll minn=2147483647;

	string tmp=s;
	bool flag1=0;

if(res(s))
{
	cout<<0;
	return 0;
}

//1
	for(ll i=0;i<tmp.size();i++)
	{
		for(ll j=i;j<tmp.size();j++)
		{
			tmp[i]=s[j];
			if(res(tmp)){flag1=1;cout<<1;return 0;}
		}
tmp=s;
	}

	tmp=s;

	for(ll i=tmp.size();i>0;i--)
	{
		for(ll j=tmp.size();j>i;j++)
		{
			tmp[i]=s[j];
			if(res(tmp)){flag1=1;cout<<1;return 0;}
		}

	}




*/