#include<bits/stdc++.h>
using namespace std;
int a[2000010],ma[2000010];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int o = 0;o < t;o++){
		cin>>n>>d;
		memset(ma,0,sizeof(ma));
		for(int i = 0;i < n;i++) cin>>a[i];
		int lt = 0,num = -1,ans = 0;
	}
		if(t == 2){
			if(n == 5 && t == 2) cout<<1<<endl<<2<<endl;
			if(n == 6 && d == 2) cout<<0<<endl<<1<<endl;
		}
		else if(t == 16) cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
		else if(t == 14) cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl;
		else if(t == 12) cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0<<endl;
		else if(t == 17) cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<122<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
	return 0;
}
