#include<bits/stdc++.h>
using namespace std;
int ans[300007],a[500007];
bool inx[300007];
int n,m;
vector<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
cin>>n>>m;
memset(inx,false,sizeof(inx));
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
for(int j=1;j<=n;j++)
{
	for(int i=j;i<=n;i++)
{

		while(inx[a[i]])
		{
			inx[s.back()]=false;
			s.pop_back();
		}
		s.push_back(a[i]);
		inx[a[i]]=true;
	

}

	for(int v:s)
		{
			ans[v]++;
		}
	cout<<endl;
while(!s.empty())
{
	inx[s.back()]=false;
	s.pop_back();
}
	
}

for(int i=1;i<=m;i++)
{
	cout<<ans[i]<<" ";
}
return 0;
}
