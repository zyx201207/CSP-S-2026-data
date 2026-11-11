#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[5*N],ans[5*N];
int n,m;
list<int> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 cin>>a[i];
	for(int j=1;j<=n;j++)
	{
		q.clear();
        for(int i=j;i<=n;i++)
         {
         	q.push_back(i);
    	    if(a[q.front()]==a[q.back()]&&q.size()>1) 
    	     while(q.size()>1)
			  q.pop_front();
    	    
	     }
	    while(q.empty()==false) {
	    	ans[a[q.front()]]++;
	    	q.pop_front();
		}
	}
	for(int i=1;i<=m;i++)
	 cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
