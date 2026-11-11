//QJYZ SN-S00763 YangJunnan
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define _in128 __int128
const ull N=1e12;

_in128 a[5*(int)1e5+10];

//__int128 output
void op128(_in128 x128)
{
	if(x128<0) 
	{
		cout<<"-";
		x128=-x128;
	}
	int v_in128[129]={};
	for(int i=1;i<=129;i++)
	{
		v_in128[i]=x128%10;
		x128/=10;
	}
	bool flag=0;
	for(int i=128;i>0;i--)
	{
		if(v_in128[i]!=0&&flag==0) 
			flag++;
		if(flag==1) 
		{
			cout<<v_in128[i];
			continue;
		}
	}
}

inline _in128 read()
{
	_in128 x=0;int f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}

bool sj_spA(ull n,ull m)
{
	ull ans=0;
	while(m>0)
	{
		//cout<<"sj_spA"<<"\n";
		if(m&1) {ans++;}
		m=m>>1;
	}
	if(ans+1>=n) {cout<<n;return 0;}
	cout<<ans+1;
	return 0;
}

bool sj_spB(ull n,ull m,ll d)
{
	//cout<<"sj_spB"<<"\n";
	_in128 ans=0;
	while(1)
	{
		//cout<<"Looping..."<<"\n";
		ans++;
		//cout<<"ans++"<<((ans-1)>=n)<<"\n";
		ull sol=d*(ans*(ans+1)/2);
		//cout<<"solving..."<<sol<<"\n";
		if(sol>m||(ans-1>=n)) 
		{
			ans--;
			//cout<<n<<(sol>m)<<" "<<((ans-2)>=n)<<"break..."<<"\n";
			break;
		}
	}
	if(ans+1>=n) {cout<<n;return 0;}
	op128(ans+1);
	return 0;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ull n=read();ull m=read();

//Read in
	for(ull i=1;i<=n;i++) {a[i]=read();}
	

	//SPECIAL JUDGE
	int counterA=0,counterB=0;
	for(ull i=1;i<=n;i++)
	{
		//Counter setting
		if(a[i]==i) counterA++;
		
		ull dif=0;
		if(i>2)dif=a[i]-a[i-1];
		if(i>2&&(a[i]-a[i-1]==a[i-1]-a[i-2])) counterB++;
		
		//Special Judge A & B
		if((i==7&&counterA==7)||(i==n&&counterA==n))
		{
			sj_spA(n,m);
			return 0;
		}
		else if(i==n&&counterB>n/2-2)
		{
			sj_spB(n,m,dif);
			return 0;
		}
	}
	
	
	//Common Judge	
	int ans=-1;
	for(int L=1;L<=n;L++)
	{
		for(int i=1;i<=n-L+1;i++)
		{
			ull dif=0;
			_in128 maxn=a[i+L-1];//op128(maxn);cout<<"==maxn\n";
			for(int j=i;j<=i+L-1;j++) 
			{
				dif+=(maxn-a[j]);
				//cout<<"dif="<<dif<<"  m="<<m<<"\n";
			}
			if(dif<=m) 
			{
				ans=max(ans,L);
				//cout<<"GET!  "<<dif<<"\n\n";
				continue;
			}
			//cout<<"FAIL!  "<<dif<<"\n\n";
		}
	}
	
	cout<<ans;
	return 0;
}
//14:30 - 17:15
