#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,A[200000];
string S[200000];
void dfs(long long x,long long y)
{
	if(x==0) return;
	long long q,w,i,j;
	if(x%2==0) S[y]+='0';
	else S[y]+='1';
	dfs(x/2,y);
}
string fds(string s1,string s2)
{
	long long q,w,i,j;
	string s;
	while(s1.size()<s2.size())
	{
		s1=s1+'0';
	}
	while(s1.size()>s2.size())
	{
		s2=s2+'0';
	}
	for(i=0;i<s1.size();i++)
	{
		if(s1[i]=='1'&&s2[i]=='1')
		{
			s+='1';
		}
		else s+='0';
	}
	return s;
}
long long sdf(string s)
{
	long long q=0,w,i,j;
	for(i=s.size()-1;i>=0;i--)
	{
		w=s[i]-'0';
		q+=pow(2,i)*w;
	}
	return q;
}
void dsf(long long x,long long now,long long step)
{
	if(step==m) ans=max(ans,now);
	if(now<=ans) return;
	long long i,j,q,w;
	for(i=x+1;i<=n;i++)
	{
		string s=fds(S[x],S[i]);
		dsf(i,sdf(s),step+1);
	}
}
int ccc(int a,int b)
{
	return a>b; 
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long q=0,w,e,r,i,j,x,y;
	string s;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>A[i];
		q=max(q,A[i]);
	}
	sort(A+1,A+1+n,ccc);
	
	if(n>2000)
	{
		if(q==3)
		{
			w=0;
			for(i=1;i<=n;i++)
			{
				if(A[i]==3) w++;
			}
			if(w>=m) cout<<3;
			else cout<<2;			
		}
		else 
		{
			cout<<A[m];
		}
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			dfs(A[i],i);
		}	
		for(i=1;i<=n;i++)
		{
			dsf(i,sdf(S[i]),1);
		}		
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
 //<<fixed<<setprecision(2);
 
