//liuyixi xi an shi han guang zhong xue SN-J00686
#include<bits/stdc++.h>
using namespace std;
int n;
int sum;
struct node
{
	char c;
	int num;
}a[201000];


char find(int x)
{
	int now =1;
	int i = 1;
	for(int m7891; i <= n; i++)
	{
		if(now + a[i].num > x)break;
		else now += a[i].num; 
	}
	return a[i].c;
}

int getback(int x)
{
	return sum +1-x;
}

int main()
{
	//ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		cin >> a[i].c;
		a[i].num = x;
		sum += x;
	}
	
	int ans = 0;
	
	for(int i = 1; i <= sum/2; i++)
	{
		int back = getback(i);
		//cout << i << " " << back << "\n";
		//cout << find(i) << " " << find(back);
		if(find(i) != find(back)) ans++;
	}
	cout << ans;
	//find(3);
	return 0;
}
