#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,cyt[500050],step,max_cyt;
bool cmp(int x,int y)
{
	return x>y;
}
queue<int>q;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>cyt[i];
	sort(cyt+1,cyt+1+n,cmp);
	int linshi=0;
	for(int i=1;i<=n;i++)
	{
		q.push(cyt[i]);
		linshi=q.front();
		if(m>=linshi-cyt[i]){
			m-=linshi-cyt[i];
			step++;
			max_cyt=max(max_cyt,step);
			//cout<<linshi<<' '<<m<<"\n";
		}else{
			q.pop();
			m+=(linshi-q.front())*(step-1);
			i--;
			step--;
			//cout<<m<<"\n";
		}
	}
	cout<<max_cyt;
	return 0;
}




