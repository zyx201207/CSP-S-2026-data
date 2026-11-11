#include<bits/stdc++.h>
using namespace std;
int ans=0,bye=0,num=0;
char b[1000000]={'0'};
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
    {
    	int a=0;
    	char c=0;
    	cin>>a>>c;
    	ans+=a;
    	for(int j=1;j<=a;j++)
        {
        	b[bye]=c;
        	bye++;
		}
	}
	for(int i=1;i<=ans/2;)
    {
    	if(b[i]!=b[ans-1])num++;
    	ans--;
	}
	cout<<num;
	return 0;
}