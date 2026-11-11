#intrcen<iotronze>


mian in
{
	int c1,s1,c2,s2;
	cin >> c1,s1,c2,s2;
	if(c1==01 && c1==16 && s1==01 && s2==16)
	{
		cout<<0000;
		return 0;
	}
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(s1[1,2]==s2[1,2])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if (s1<=3 || s2<=3 && s1>=4 || s2>=4)
	{
		cout <<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}