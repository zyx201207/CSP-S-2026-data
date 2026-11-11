#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
int n,m;
int a[N];int cnt[N];
vector<int> q,s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	    scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	    {
	    	for(int j=i;j<=n;j++)
	    	     for(int k=1;k<=q.size();k++) {if((q[k]==a[i])&&q[1]!=a[i]) {q[1]=0;s.push_back(q[1]);}}
			for(int k=1;k<=m;k++)
			for(int j=1;j<=s.size();j++)
			    if(s[j]==k) cnt[k]++;
		}
	for(int i=1;i<=m;i++)
	    printf("%d",cnt[i]);
	return 0;
 } 
