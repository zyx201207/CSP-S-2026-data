#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1000005;
LL n,m;
LL a[N],d[N],su[N];
string tos(LL s)
{
	string t="";
	while(s>0)
	{
		t+=(s%10+'0');
		s/=10;
	}
	return t;
}
string add(string a,string b)
{
	if(a.length()<b.length())
	{
		swap(a,b);
	}
	LL la=a.length(),lb=b.length();
	string s="";
	int f=0;
	for(int i=0;i<lb;i++)
	{
		if(f==1)a[i]+=1; 
		s+=(a[i]-'0'+b[i]-'0');
		if(s[i]>=10)
		{
			f=1;
			s[i]-=10;
		}
		else
		{
			f=0;
		}
		s[i]+='0';
	}
	for(int i=lb;i<la;i++)
	{
		if(i==lb && f==1)
		{
			s+=a[i]+1;
		}
		else s+=a[i];
	}
	if(lb==la)s+='1';
	return s;
}
LL mult(LL x,LL y)
{
	bool u=0;
	if(x<0)
	{
		x=abs(x);
		u=1;
	}
	string a=tos(x),b=tos(y);
	if(a.length()<b.length())
	{
		swap(a,b);
		//cout<<a<<' '<<b;
	}
	LL la=a.length(),lb=b.length();
	string s="",li="";
	int f=0,p=0;
	for(int i=0;i<lb;i++)
	{
		string s1="";
		char b1=b[i]-'0';
		for(int j=0;j<la;j++)
		{
			int x=((a[j]-'0')*b1);
			if(f!=0)x+=f;
			if(x>=10)
			{
//				int y=s1[i];
//				cout<<y<<' ';
				f=x/10;
				s1+=(x%10+'0');
				//cout<<s1[i]<<endl<<endl;
			}
			else
			{
				f=0;
				s1+=('0'+x);
			}
			//cout<<s1[i]<<"  ewfe"<<endl<<endl;
		}
		string y=li+s1;
		//cout<<s1;//<<"    "<<y<<endl;
		s=add(s,y); 
		li+='0';
	}
	if(f!=0)
	{
		s+=(f+'0');
	}
	LL as=0,p1=1;
	for(int i=0;i<s.length();i++)
	{
		as+=(s[i]-'0')*p1;
		p1*=10;
	}
	if(u==1)
	{
		return -1*as;
	}
	return as;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	//	su[i]=su[i-1]+i;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
	}
	LL s=0,ans;
	for(int i=2;i<=n;i++)
	{
		s=s+mult(d[i],i-1);
	//	cout<<i<<' '<<s<<' '<<d[i]<<' '<<d[i]*(i-1)<<endl;
		if(s>m)
		{
			ans=i-1;
			break;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
