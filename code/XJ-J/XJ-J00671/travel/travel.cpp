
string b,c;
set<string>s;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(i=1;i<=2;i++)
		cin>>a[i];
	s1=a[1]*10+a[2];
	for(i=3;i<=4;i++)
	cin>>a[i];
	s2=a[3]*10+a[4];
	cin>>b;
	for(i=5;i<=6;i++)
	s3=a[5]*10+a[6];
	for(i=7;i<=8;i++)
	s4=a[7]*10+a[8];
	cin>>c;
	s.insert(b);
	{
	cin>>a[i];
	s2=a[5]*10+a[6];for(i=7;i<=8;i++)
	cin>>a[i];
	s4=a[7]*10+a[8];
	cin>>c;
	s.insert(c);
	if(s1==s3)
	cout<<1;
	else
	cout<<0;
	if(s2==s4)
	cout<<1;
	else
	cout<<0;
	cout<<0;
	cout<<0;
	return 0;
}
}
	       