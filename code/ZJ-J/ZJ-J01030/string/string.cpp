#include<bits/stdc++.h>
using namespace std;
struct qj
{
	char c;
	long long st;
	long long ed;
};
vector<qj> x;
int main()
{
	ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long length=0;
	long long lx=-1;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		if(lx==-1)
		{
			qj tmp;
			tmp.c=c;
			tmp.st=0;
			tmp.ed=a-1;
			x.push_back(tmp);
			lx++;
		}
		else if(x[lx].c==c)
		{
			x[lx].ed+=a;
		}
		else
		{
			qj tmp2;
			tmp2.c=c;
			tmp2.st=length;
			tmp2.ed=length+a-1;
			x.push_back(tmp2);
			lx++;
		}
		length+=a;
	}
	long long ans=0;
	long long i=0;
	long long now=0;
	while(i<length/2)
	{
		
		if(i>x[now].ed)
		{
			now++;
		}
		if(length-i-1<x[lx].st)
		{
			lx--;
		}
		//cout<<"i="<<i<<",nowl="<<now<<",nowr="<<lx<<endl;
		long long left=x[now].ed-i+1;
		long long right=length-i-x[lx].st;
		long long lr=min(left,right);
		//cout<<"lr="<<lr<<"(l="<<left<<",r="<<right<<")"<<endl;
		if(x[now].c!=x[lx].c)
		{
			ans+=lr;
		}
		i+=lr;
	}
	cout<<ans;
	return 0;
}
