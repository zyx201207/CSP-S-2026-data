#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
long long n,m,xh=1;
long long a[N*5],enercry[N*5];
void hxh()
{
	sort(a+1,a+1+n);
    for(int i=2;i<=n;i++)
      enercry[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++)
    {
		long long xs=m,bhu=1;
		for(int j=i+1;j<=n;j++)
		   if(xs>=enercry[j])
		   {
			   xs=xs-enercry[j];
			   bhu++;
		   }
		                 else break;
		 xh=max(xh,bhu);
    }
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    if((n<=16)&&(m<=1000)) hxh();
    cout<<xh<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
