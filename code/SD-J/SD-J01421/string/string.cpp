#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
long long ct[201];
struct node
{
	long long num1,num2,pos;
}tmpl[N],tmpr[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	int n,cnt=0;
	bool b=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		if(c[i]!=c[i-1]&&i>1) b=0;
		cnt+=a[i];
		ct[c[i]]+=a[i];
	}
	if(b)
	{
		cout<<0;return 0;
	}
	for(int i=1;i<=26;i++)
	{
		char d=i+96;
		int l=-1,r=-1,tl=0,tr=0;
		long long cntl=0,cntr=0;
		for(int j=1;j<=n/2;j++)
		{
			cntl+=a[j];
			if(c[j]==d&&cntl<cnt/2)//发现目标字符，暂存待后续处理 
			{
				l=j;
				tmpl[++tl].pos=l;
				tmpl[tl].num1=cntl-a[j];//start
				tmpl[tl].num2=cntl;//end
				
			}
			cntr+=a[n-j+1];
			if(c[n-j+1]==d&&cntr<cnt/2)
			{
				r=j;
				tmpr[++tr].pos=r;
				tmpr[tr].num1=cntr-a[n-j+1];
				tmpr[tr].num2=cntr;
			}
			int k=min(tl,tr);
			if(k>0)
			{
				int kl=k,kr=k;
				while(tmpl[kl].num1>tmpr[kr].num2)
				{
					if(kr!=k) kr--;
					if((tmpl[kl].num1<=tmpr[kr].num2&&tmpr[kr].num1<=tmpl[kl].num2)||kr<0) break;
				}
				while(tmpr[kr].num1>tmpl[kl].num2)
				{
					if(kl!=k) kl--;
					if((tmpl[kl].num1<=tmpr[kr].num2&&tmpr[kr].num1<=tmpl[kl].num2)||kl<0) break;
				}
				while(tmpl[kl].num1<=tmpr[kr].num2&&tmpr[kr].num1<=tmpl[kl].num2)
				{
					long long num1,num2;
					num1=max(tmpl[kl].num1,tmpr[kr].num1);
					num2=min(tmpr[kr].num2,tmpl[kl].num2);
					ct[d]-=(num2-num1);
					if(tmpl[kl-1].num1<=tmpr[kr].num2&&tmpr[kr].num1<=tmpl[kl-1].num2)
					{
						kl--;continue;
					}
					else if(tmpl[kl].num1<=tmpr[kr-1].num2&&tmpr[kr-1].num1<=tmpl[kl].num2)
					{
						kr--;continue;
					}
					else break;
				}
			}
			
		}
		for(int j=1;j<=tl;j++)
		{
			tmpl[j].pos=0;
			tmpl[j].num1=0;//start
			tmpl[j].num2=0;
		}
		for(int j=1;j<=tr;j++)
		{
			tmpr[j].pos=0;
			tmpr[j].num1=0;
			tmpr[j].num2=0;
		}
	}
	long long ans=0;
	for(int i=1;i<=26;i++)
	{
		int d=i+96;ans+=ct[d];
	}
	cout<<ans/2;
	return 0;
 } 
