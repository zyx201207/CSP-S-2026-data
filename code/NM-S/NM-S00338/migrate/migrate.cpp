#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,v[2000005],w,tong[2000005],ww,vvv=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{tong[1]=1;vvv=0;
		cin>>n>>d;
		if(d==1) {cout<<0<<endl;continue;}
	    for(int i=2;i<=n;i++) tong[i]=0;
		for(int i=1;i<=n;i++) cin>>v[i];
		v[n+1]=2e9;v[0]=-2e9;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n+1;j++)
		      if(v[i]+d<v[j]) {w=j-1;break;}
		    if(w==i) break;
		      else {i=w;tong[i]=1;}
		}
		
		for(int i=n;i>=1;i--)
		  if(tong[i]==1) {ww=i;break;}
		tong[ww]++;
		for(int i=ww;i>=1;i--)
		{
			for(int j=i-1;j>=0;j--)
		      if(v[i]-d>v[j]) {w=j+1;break;}
		    if(w==i) break;
		      else {i=w;tong[i]++;}
	    }
		for(int i=1;i<=ww;i++)
		  if(tong[i]>=1) vvv++;
		cout<<vvv-1<<endl;
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
