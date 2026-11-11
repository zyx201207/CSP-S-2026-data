#include<iostream>
using namespace std;
int c,t,n;
long long d,x[2000005],wow[2000005];
long long ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){cin>>x[i];}
		if(c==11||c==12)
		{
//			cout<<d<<" "<<x[2]-x[1]<<"\n";
			if(d<=x[2]-x[1]||x[2]-x[1]==0){cout<<"0\n";continue;}
			long long wow=(d)/(x[2]-x[1]);
//			cout<<wow<<"\n";
			cout<<max(0ll,(n-1)-(2*wow-1)+1)<<"\n";
			continue;
		}
		for(int l=1;l<=n;l++)
			for(int r=l;r<=n;r++)
			{
				if(r-l+1<=3){continue;}
				bool flag=0;
				for(int i=l+1;i<=r;i++)
				{
					if(x[i]-x[i-1]>d){flag=1;break;}
				}
				if(flag){continue;}
				int cnt=0;wow[++cnt]=l;
				int i=l,j=l;
				while(i<=j&&j<r)
				{
					while(x[j]-x[i]<=d&&j<=r){j++;}
					j--;
					wow[++cnt]=j;
					i=j;
				}
				int ge=0;
//				for(int i=1;i<=cnt;i++){cout<<wow[i]<<" ";}cout<<"\n";
				for(int i=2;i<cnt;i++)
				{
					if(wow[i]-wow[i-1]>1&&x[wow[i+1]]-x[wow[i]-1]<=d){ge++;}
					if(wow[i]-wow[i-1]>2&&x[wow[i+1]]-x[wow[i]-2]<=d){ge++;}
					if(ge>1){break;}
				}
//				cout<<l<<" "<<r<<" "<<ge<<" "<<ans<<"\n";
				if(ge==1){ans++;}
			}
		cout<<ans<<"\n";
	}
	return 0;
}
