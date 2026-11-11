#include<bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	int a[200010];
	vector<int> v[50010];//cun er jin zhi
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int g[40]={1};
	for(int i=1;i<=30;i++)
		g[i]=g[i-1]*2;
	for(int i=1;i<=n;i++)
		for(int j=30;j>=0;j--)
		{
			if(a[i]>=g[j]){
				a[i]-=g[j];
				v[i].push_back(1);}
			else v[i].push_back(0);
		}
//	for(int i=0;i<v[5].size();i++)cout<<v[5][i];
	vector<int>q[40];
	for(int i=30;i>=0;i--)
		for(int j=1;j<=n;j++)
			if(v[j][i]==1)
				q[i].push_back(j);
//	for(int i=0;i<=30;i++)
//		cout<<q[i].size()<<" ";
	int mn=INT_MAX;
	int f=-1;
	for(int i=0;i<=30;i++)
		if(q[i].size()>=m)
		{
			f=i;//di ige shu di yici chuxian//f=27
			break;
		}
	if(f==-1){cout<<0;return 0;}
		int cnt=0;
		deque<int>pub;
		deque<int>pub2;
		pub2.push_back(f);
		for(int i=0;i<=q[f].size();i++)
			pub.push_back(q[f][i]);
	for(int i=f+1;i<=30;i++)//q[i][?]
	{
		cnt=0;
		for(int j=0;j<=q[i].size()-1;j++)//q[i][j]
			if(v[q[i][j]][f]==1) cnt++;
		if(cnt>=m)
		{
		pub2.push_back(i);
			for(int j=0;j<=q[i].size()-1;j++)//q[i][j]
				if(v[q[i][j]][f]==1) 
					pub.push_back(q[i][j]);
			while(pub[0]<pub[1])
				pub.pop_front();
			pub.pop_front();
			while(!pub[0])
			pub.pop_front();
		}
	}
		
//		cout<<pub2[1];
	int sum=0;
	for(int i=0;i<pub2.size();i++)
		sum+=g[30-pub2[i]];
	cout<<sum;
		
		
	
		
	return 0;
}
