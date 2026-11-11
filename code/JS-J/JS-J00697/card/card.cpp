#include<bits/stdc++.h>
using namespace std;
long long q[2000005][5],rec[500005],cnt = 1;
long long tag[2000005];
void query(long long l,long long r,long long i)
{
	q[i][1] = l;
	q[i][2] = r;
	if(r == l)
	{
		q[i][3] = 0;
		rec[cnt] = i;
		cnt++;
	}
	else
	{
		int mid = (l + r) / 2;
		query(l,mid,2 * i);
		query(mid + 1,r,2 * i + 1);
	}
	q[i][3] = q[2 * i][3] + q[2 * i + 1][3];
	return;
}
void lazy(int l,int r,int i)
{
	int mid = (q[i][1] + q[i][2]) / 2;
	if(q[i][1] == q[i][2])
	{
		q[i][3] += tag[i];
		tag[i] = 0;
		return;
	}
	if((r > mid) &&(l == q[i][1]))
	{
		lazy(mid + 1,r,2 * i + 1);
		tag[2 * i] = tag[i];
		tag[i] = 0;
		return;
	}
	if((l <= mid) &&(r == q[i][2]))
	{
		lazy(l,mid,2 * i);
		tag[2 * i + 1] = tag[i];
		tag[i] = 0;
		return;
	}
	if((l <= mid))
	{
		lazy(l,r,2 * i);
		tag[i] = 0;
		return;
	}
	if((r > mid))
	{
		lazy(l,r,2 * i + 1);
		tag[i] = 0;
		return;
	}
	if((l <= mid) &&(r > mid))
	{
		lazy(l,mid,2 * i);
		lazy(mid + 1,r,2 * i + 1);
		tag[i] = 0;
		return;
	}
}
long long check(int num,int i)
{
	int mid = (q[i][1] + q[i][2]) / 2;
	if(mid >= num)
	{
		if(tag[i] != 0)
	    {
			lazy(tag[i],2 * i);
			lazy(tag[i],2 * i + 1);
			tag[i] = 0;
	    }
	    return check(num,2 * i);
	}
	else if(q[i][2] < num)
	{
		if(tag[i] != 0)
	    {
			lazy(tag[i],2 * i);
			lazy(tag[i],2 * i + 1);
			tag[i] = 0;
	    }
	    return check(num,2 * i);
	}
	q[i][3] += tag[i];
	tag[i] = 0;
	return q[i][3];
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m,a[500005];
	bool used[500005];
	memset(used,0,sizeof(used));
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	query(1,n,1);
	while(n >= 1)
	{
		if(!used[n]) 
		{
			tag[1] = n;
			lazy(n,n,1);
			used[n] = 1;
		}
		else
		{
			tag[1] = (-1 * n);
			lazy(n + 1,used[n] - 1,1);
		}
		n--;
	}
	for(int i = 1;i <= n;i++)
	{
		cout << check(i,1) << endl;
	}
	return 0;
}
