#include<bits/stdc++.h>
using namespace std;
const int N=2*100000+5;
struct Node{
	
    long long a;
    char b;
} node[N];
long long ans,len,l,r;
int n;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	    for(int i=1;i<=n;i++)
	    {
		    long long a1;
		   char b1;
		    cin>>a1>>b1;
		    len+=a1;
		    if(len<2000000)
		    {
		    for(int i=len-a1;i<=len;i++)
		        s[i]=b1;
			}
		    if(node[i-1].b==b1)
		   {
			   node[i-1].a+=a1;
			   n--;
			   i--;
		    }
		    else
		    {
		        node[i].a=node[i-1].a+a1;
		        node[i].b=b1;
		    }
	     }
	     if(len<2000000)
	     {
	    for(int i=1;i<=len/2;i++)
	    {
		    if(s[i]!=s[len-i+1]) ans++;
	    }
	    cout<<ans;
		}
		else 
		{
	     if(n==1) cout<<0;
	     else{
	     if(n==2) cout<<node[2].a-node[1].a;
	     else
	     {
			 
	for(int i=1;i<=n;i++)
	{
		if(node[i].a==0) continue;
		long long cha=max(node[i].a,node[n-i+1].a)-min(node[i].a,node[n-i+1].a);
		if(node[i].b==node[n-i+1].b) 
		{
			node[i].a-=cha;
			node[n-i+1].a-=cha;
		}
		else {
			
		   ans+=min(node[i].a,node[n-i+1].a);
		   node[i].a-=min(node[i].a,node[n-i+1].a);
		   node[n-i+1].a-=min(node[i].a,node[n-i+1].a);
		}
	}
	cout<<ans;}}
		}
	return 0;
}
