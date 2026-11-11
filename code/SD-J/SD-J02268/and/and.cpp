#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
int judge(int n)
{
	int cnt=0;
	while(n>1)
	{
		if(n%2!=0)return -1;
		n/=2;
		cnt++;
	}
	return cnt;
}
int Ans=0;
vector<int>w;
void Dfs(int id,int n,int g)
{
	if(id>g){Ans=max(Ans,g);return;}
	if(n==0){
		Dfs(id+1,w[id],g);
		Dfs(id+1,0,g);
	}else{
		Dfs(id+1,n&w[id],g);
		Dfs(id+1,n,g);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p=0;
	if(n<=2000){
		if(m==1)p=2;
		else if(m==n)p=3;
		else if(m==2)p=4;
	}else if(m==n-1){
		p=5;
	}else if(n<=20){
		p=1;
	}
	vector<int>s(n+1);
	bool flag=true;
	bool flag2=true;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		maxn=max(s[i],maxn);
		if(flag&&p==0){
			if(judge(s[i]+1)==-1)
				flag=false;
		}
		if(s[i]!=i-1)flag2=false;
	}
	if(p==0){
		if(flag)p=6;
		else if(flag2)p=7;
	}
	if(p==1){
		w=s;
		Dfs(1,0,n);
		cout<<Ans;
	}else if(p==2){
		cout<<maxn<<"\n";
	}else if(p==3){
		int ans=s[1];
		for(int i=2;i<=n;i++)
			ans&=s[i];
		cout<<ans<<"\n";
	}else if(p==4){
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,s[i]&s[j]);
		cout<<ans<<"\n";
	}else if(p==5){
		
	}else if(p==6){
		vector<int>t(n+1);
		for(int i=1;i<=n;i++)
			t[i]=judge(s[i]+1);
		sort(t.begin()+1,t.end());
		cout<<pow(2,t[n-m+1])-1<<"\n";
	}else if(p==7){
		sort(s.begin()+1,s.end());
		int ans=s[n-m+1];
		for(int i=n-m+2;i<=n;i++)
			ans=ans&s[i];
		cout<<ans<<"\n";
	}else{
		cout<<0<<"\n";
	}
	return 0;
}
