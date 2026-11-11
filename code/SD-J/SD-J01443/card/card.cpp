# include<bits/stdc++.h>
using namespace std;
const int MX = 5e5;
int a[MX + 10],ans[MX + 10];
bool f[MX + 10];
int cnt;
int n,m;

void solve_baoli()
{
	for(int i = 1;i <= n;i++)
	{
		bool fl = false;
		memset(f,false,sizeof(f));
		for(int j = i;j <= n;j++)
		{
			fl = false;
			for(int k = i;k < j;k++)
			{
				fl = fl || (!f[k] && (a[k] == a[j]));
				f[k] = f[k] || fl;
		//		cout << k << ":" << fl << endl;
			}
		}
		for(int j = i;j <= n;j++)
		{
			ans[a[j]]+=!f[j];
		}
	}
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
///	multiset<int> s;
	bool ok = true;;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		ok = ok && (a[i] >= a[i - 1]);
//		s.insert(a[i]);
	}
	if(ok)
	{
		for(int i = 1;i <= n;i++)
		{
			if(a[i + 1] > a[i])
			{
				ans[a[i]] = i;
			}
		}
		ans[a[n]] = n;
		for(int i = 1;i <= m;i++)
		{
			cout << ans[i] << " ";
		}
		return 0;
	}
	solve_baoli();
	/*
	stack<int> t;
	multiset<int> st;
	for(int i = 1;i <= n;i++)
	{
		s.erase(s.lower_bound(a[i]));
	//	cout << s.count(a[i]) << " ";
		cnt-=f[a[i]];
		f[a[i]] = s.count(a[i]) && st.count(a[i]);
		cnt+=f[a[i]];
		while(st.count(a[i]) && t.size())
		{
			st.erase(st.lower_bound(t.top()));
			cnt-=f[t.top()];
			f[t.top()] = s.count(t.top()) && st.count(t.top()); 
		//	cout << f[t.top()] << " ";
			cnt+=f[t.top()];
			t.pop();
		}
	//	if(t.size()) cout << t.top() << endl;
    //    cout << cnt << endl;
	//	cout << " ";
		if(!s.count(a[i])) ans[a[i]] = max(ans[a[i]],(i - 1) * (!cnt) + 1);
		t.push(a[i]);
		st.insert(a[i]);
		cnt-=f[a[i]];
		f[a[i]] = s.count(a[i]) && st.count(a[i]);
//		cout << f[a[i]] << endl;
		cnt+=f[a[i]];
	}*/
	for(int i = 1;i <= m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
