//QJYZ SN-J01345 YangJunnan
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node
{
	int m;
	char c;
};
/*
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string s;
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int m=0;cin>>m;
		char c;cin>>c;
		for(int i=1;i<=m;i++)
		{
			s+=c;
		}
	}
	
	int len=s.length();
	long long ans=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]!=s[len-1-i]) ans++;
	}
	
	cout<<ans/2;
	return 0;
}
*/
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string s;
	int n;
	cin>>n;
	
	queue<node> q[2];
	int ve[N];
	char ch[N];
	for(int i=1;i<=n;i++)
	{
		cin>>ve[i];
		cin>>ch[i];
	} 
	for(int i=1;i<=n;i++)
	{
		int m1=ve[i];
		char c1=ch[i];
		int m2=ve[n-i+1];
		char c2=ch[n-i+1];
		q[0].push({m1,c1});
		q[1].push({m2,c2});
		//cout<<m1<<" "<<c1<<endl;
	}
	
	unsigned long long ans=0;
	int len=q[0].size();
	while((!q[0].empty())&(!q[1].empty()))
	{
		/*cout<<"in access"<<endl;*/
		node a=q[0].front(),b=q[1].front();
		if(a.c==b.c&&a.m==b.m) {/*cout<<"same!"<<endl;*/q[0].pop();q[1].pop();continue;}
		else if(a.m==b.m&&a.c!=b.c) {/*cout<<"sm but ans+"<<a.m<<" now ans "<<ans<<endl;*/ans+=a.m;q[0].pop();q[1].pop();continue;}
		else if(a.m!=b.m) {
			//cout<<"m dif! ";
			int lenth=min(a.m,b.m);
			int minn,maxn;
			
			if(a.m>b.m) {minn=1;maxn=0;}
			else if(a.m<b.m) {minn=0;maxn=1;}
			
			if(a.c==b.c)
			{
				
				node aa=q[maxn].front();
				q[maxn].front()={aa.m-lenth,aa.c};
				q[minn].pop();
			}
			else
			{
			//	cout<<"ans+"<<lenth<<" now ans "<<ans<<endl;
				ans+=lenth;
				node aa=q[maxn].front();
				q[maxn].front()={aa.m-lenth,aa.c};
				q[minn].pop();
			}
		}
	//	cout<<"role access"<<endl;
	}
	cout<<ans/2;
	return 0;
}

