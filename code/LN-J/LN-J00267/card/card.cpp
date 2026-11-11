#include<bits/stdc++.h>
using namespace std;
const int N=10;
int a[N],ans1=0,ans2=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int b=0,c=0;
		for(int j=i;j<=n;j++)
		{
			if((a[j]==1&&b==1)||(a[j]==2&&c==1)) b=0,c=0;
			else if(a[j]==1&&b==0) b=1;
			else if(a[j]==2&&c==0) c=1;
	    }
	    if(b==1) ans1++;
	    if(c==1) ans2++;
	}
	cout<<ans1<<" "<<ans2;
    return 0;
}
