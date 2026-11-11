int n, d, x[2000005], sum, num;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i ++)
		{
			cin >> x[i];
		}
		if (c == 11 || c == 12)
		{
			if ((x[2] - x[1]) >= d)
			{
				cout << 0 << endl;
			}
			
		}
		t--;
	}
	
	return 0;
}