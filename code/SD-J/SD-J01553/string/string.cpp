#include<bits/stdc++.h>
using namespace std;
char ch[200005],v;
int a[200005],n;
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n); 
	for(int i=1;i<=n;i++)
		scanf("%d%c%c",&a[i],&v,&ch[i]);
		
	for(int i=1,j=n;i<j;i++,j--)
	{
		if(ch[i]!=ch[j])
		{
			if(a[i]>a[j])
			{
				a[i]-=a[j];
				sum+=a[j];
				i--;
			}
			else if(a[j]>a[i])
			{
				a[j]-=a[i];
				sum+=a[i];
				j++;
			}
			else if(a[i]==a[j])
				sum+=a[i];
			
		}
		else
		{
			if(a[i]>a[j])
			{
				a[i]-=a[j];
				i--;
			}
			else if(a[j]>a[i])
			{
				a[j]-=a[i];
				j++;
			}
		}
	}
	printf("%lld\n",sum);
	return 0 ;
}


