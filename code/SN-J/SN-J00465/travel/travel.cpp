#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a1,b1;
	int n=4;
	char a[2],s[2],c[3],b[3];
	int d[n];
	cin>>a[1]>>a[2]>>c[1]>>c[2]>>c[3]>>s[1]>>s[2]>>b[1]>>b[2]>>b[3];      
    if(a[1]==s[1]&&a[2]==s[2])
    {
    	d[1]=1;
    	
	if(c[1]==b[1]&&c[2]==b[2])
	{
		d[2]=1;
		if(c[3]<='C'&&b[3]<='C')
		{
			d[3]=1;
			if(c[3]=='A'&&b[3]=='B'||c[3]=='B'&&b[3]=='A'||c[3]=='B'&&b[3]=='C'||c[3]=='C'&&b[3]=='B'){
				d[4]=1;
			}
		}
		else if(c[3]>='D'&&b[3]>='D')
		{
			if(c[3]=='F'&&b[3]=='D'||c[3]=='D'&&b[3]=='F'){
				d[4]=1;
			}
			d[3]=1;
			
		}
		else {
			cout<<"1100";
			return 0;
				fclose(stdin);
	    fclose(stdout);
		}
	}else{
		cout<<"1000";
		return 0;
			fclose(stdin);
	    fclose(stdout);
	}
    
	}else
	{
		cout<<"0000";
		return 0;
			fclose(stdin);
	    fclose(stdout);
	}
	if(d[4]!=1)
	{
		cout<<"1110";
		return 0;
		fclose(stdin);
	    fclose(stdout);
	}
	for(int i=1;i<=n;i++)
	{
		cout<<d[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
