#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>x>>c>>d>>y;
	int sum=0,ans=0,cnt=0,wns=0;
	if(a==c)
	{
		sum=1;
		if(b==d)
		{
			ans=1;
			if(b==d&&(x<='C'&&y<='C')||(x>'C'&&x<='D'&&y>'C'&&y<='D'))
			{
				cnt=1;
				if((x+1==y||x-1==y)&&(x!='C'&&y!='D'))wns=1;
			}
		}
	}
	cout<<sum<<ans<<cnt<<wns;
	return 0;
}
