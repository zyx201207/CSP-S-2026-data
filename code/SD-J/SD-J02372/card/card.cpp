#include <bits/stdc++.h>
using namespace std;
int n,m,z,ans[300005];
bool vis[500005],flag;
queue<int>a;
queue<int>b;
int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>z;
		a.push(z);
	 } 
	for(int i=1;i<=n;i++)
	{
		for(int y=1;y<=a.size();y++)
		{
			if(vis[a.front()]) {
				int c=b.size();
				for(int j=1;j<=c;++j){
					if(b.front()==a.front())
					{
						flag=1;
						b.pop();
					}
					else if(flag==1)
					{
						vis[b.front()]=0;
						b.pop();
					}
					else{
						b.push(b.front());
						b.pop();
					}
				}
			}
			b.push(a.front());
			vis[a.front()]=1;
			a.push(a.front());
			a.pop();
			flag=0;
		}
		int d=b.size();
		for(int k=1;k<=d;k++){
			ans[b.front()]++;
			vis[b.front()]=0;
			b.pop();
		}
		a.pop();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
	fclose(stdin);
    fclose(stdout);
}
