#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
const ll N=2e6+8;
ll n,index[N],c,T,d,ans,rec2=0,a,b;
bool flag,flagA,flagB,flagC;
vector <int> twowayin,twowayout;
ll read(){
	ll base=0,sign=1;
	char ch;
	ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') sign=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		base=(base<<3)+(base<<1)+ch-'0';
		ch=getchar();
	}
	return base*sign;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();T=read();
	while(T--)
	{
		flagA=1;flagB=1;flagC=1;
		twowayin.clear();
		twowayout.clear();
		ans=0;rec2=0;
		n=read();d=read();
		for(int i=1;i<=n;i++)
		{
			index[i]=read();
			if(i>=3&&index[i]-index[i-1]!=index[i-1]-index[i-2]) flagA=0;
		}
		/*for(int i=1;i<n;i++)
		{
			if(i+2>n||(index[i+1]-index[i]<=d&&index[i+2]-index[i]>d))
			{
				onewayin.push_back(i);
				onewayout.push_back(i+1);
			}
		}*/
		if(flagA==1)
		{
			ll diff=index[2]-index[1];
			if(d<diff*2) cout<<0<<endl;
			else cout<<max(n-(2*(d/diff)-1),0ll)<<endl;
		}
		else
		{
			for(int i=1;i+3<=n;i++)
			{
				if(index[i+3]-index[i]>d&&index[i+3]-index[i+1]<=d&&index[i+2]-index[i]<=d)
				{
					rec2++;
					twowayin.push_back(i);
					twowayout.push_back(i+3);
				}
			}
			for(int i=0,st,ed;i<rec2;i++)
			{
				flag=1;
				a=1;
				st=twowayin[i];
				while(1)
				{
					if(st!=2&&(st==1||(!(index[st]-index[st-2]>d&&index[st]-index[st-1]<=d)))) break;
					st--;a++;
				}
				b=1;
				ed=twowayout[i];
				while(1)
				{
					if(ed!=n-1&&(ed==n||(!(index[ed+2]-index[ed]>d&&index[ed+1]-index[ed]<=d)))) break;
					ed++;b++;
				}
				if(i!=rec2-1&&twowayin[i+1]-twowayin[i]<=3) {flag=0;ans+=a;}
				if(i!=0&&twowayin[i]-twowayin[i-1]<=3) {flag=0;ans+=b;}
				if(flag) ans+=a*b;
				//cout<<flag<<" "<<a<<" "<<b<<endl;
			}
			
			cout<<ans<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
