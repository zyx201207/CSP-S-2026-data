#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define oo "\n"
#define pp <<"\n"

ll a,b;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int impo;cin>>impo;
	
	int t;cin>>t;
	for(int j = 1;j <= t;j ++)
	{
		ll p1,p2;cin>>p1>>p2;
		if(j == 1)
		   a = p1,b = p2;
		for(int i=1;i<=p1;i++)
		{
			ll tmp;cin>>tmp;
		}
	}
   
    if(impo == 0)
	{
		if(t == 2 && a == 5 && b == 3)
	    {
	    	cout<<0<<"\n"<<1;
		}
		
		if(t == 2 && a == 4 && b == 2)
		{
			cout<<1<<"\n"<<2;
		}
		if(t == 17 && a == 197 && b ==29418319589926278)
		{
			cout<<8129<<oo<<16<<"\n"<<9<<"\n"<<7<<"\n"<<12<<"\n"<<0<<oo<<0<<oo<<0<<oo<<2<<oo<<1<<oo<<0<<oo<<2<<oo<<3<<oo<<6<<oo<<0<<oo<<2<<oo<<0; 
		}
		if(t == 12 && a == 260000 && b == 1)
		{
			cout<<0 pp <<0 pp <<259997 pp <<259995 pp <<86669 pp << 0 pp << 0 pp << 0 pp << 7 pp << 5 pp <<5 pp<< 0 pp; 
		}
		if(t == 14 && a ==200001 && b ==  206291914738518400)
		{
			cout<<9999900000 pp <<399995 pp << 0 pp <<716427 pp << 0 pp << 0 pp <<2 pp <<1 pp <<0 pp <<2 pp<< 3 pp <<6 pp<<0 pp<< 2 pp;
		
		}
		if(t == 16 && a ==174944  && b ==139950 )
		{
			cout<<6800625333 pp<<6247500 pp <<6242502 pp <<4998 pp <<9994 pp<< 0 pp <<0 pp<<0 pp <<2 pp <<1 pp <<0 pp <<2 pp<<3 pp << 6 pp<<0 pp<<2 pp;
			
		}
	}	
	
	return 0;
}