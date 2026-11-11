#include<bits/stdc++.h>
using namespace std;
int n,a[100000005],ans,x,sum;
char b[100000005],c[100000005],d[100000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	x=1;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>b[i];
  	    ans+=a[i];
   	    for(int j=x;j<=ans;j++){
   		c[j]=b[i];
		}
	    x+=a[i];
	}
	for(int i=1;i<=ans;i++){
		d[ans-i+1]=c[i];
	}
	for(int i=1;i<=ans/2;i++){
		if(c[i]!=d[i])sum++;
	}
	cout<<sum;
	return 0;
}




