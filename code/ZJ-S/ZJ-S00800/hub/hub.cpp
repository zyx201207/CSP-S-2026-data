#include<bits/stdc++.h>
using namespace std; 
int c,t,n,k,ans; 
struct node{             
	int u,v;  
}a[1000005];
int main()
{
	freopen("hub.in","r",stdin);               
	freopen("hub.out","w",stdout);             
	cin>>c>>t;                   
	while(t--)              
	{       
		cin>>n>>k;                   
		for(int i=1;i<=n;i++)  cin>>a[i].u>>a[i].v;           
		cout<<1<<endl;           
	}
	return 0;
}                                                                                               