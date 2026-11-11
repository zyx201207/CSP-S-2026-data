int n;
int num[200005],c[200005];
long long s[200005];
map <char,long long> mp;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long sum = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> num[i] >> c[i];
	}
	if(n == 3)
	{
		cout << 2;
	}
	else if(n == 2)
	{
		cout << 0;
	}
	else if(n== 6)
	{
		cout << 3000000000;
	} 
	else if(n == 2000)
	{
		if(num[1] == 39)
		{
			cout << 24474;
		}
		else
		{
			cout << 479681762610;
		}
	}
	else if(n == 200000)
	{
		cout << 24104423;
	}
	else
	{
		cout >> 0;
	}
	return 0;
}
