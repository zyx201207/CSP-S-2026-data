#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
 
struct node
{
	long long x;
	char c; 
} a[N];

stack<node> r,l,t; 

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	

	long long len = 0;
	
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i].x >> a[i].c;
		
		len += a[i].x;
		
	}
	
	
	int i = 1;
	long long ls = 0;
	
	while(i <= n && ls + a[i].x <= len / 2)
	{
		ls += a[i].x;
		l.push({a[i].x,a[i].c});
		i++;
	}
		
	if(len % 2 == 1)
		a[i].x--;
		
	long long tl = len / 2 - ls ,tr = a[i].x - tl;
	
	if(tl != 0)
		l.push({tl,a[i].c});
	
	if(tr != 0)
		r.push({tr,a[i].c});
		
	i++;
	
	while(i <= n)
	{
		r.push({a[i].x,a[i].c});
		i++;
	}
	
	while(!l.empty())
	{
		t.push(l.top());
		l.pop();
	}
	
	long long cnt = 0;
	
	while(!t.empty() && !r.empty())
	{
		node a = t.top(),b = r.top();
		
		t.pop(),r.pop();
		
		long long mxs = min(a.x,b.x),as = a.x - mxs,bs = b.x - mxs;
		
		if(a.c != b.c)
			cnt += mxs;
		
		if(as != 0)
			t.push({as,a.c});
			
		if(bs != 0)
			r.push({bs,b.c});
	}
	
	cout << cnt << '\n';
	return 0;
}
