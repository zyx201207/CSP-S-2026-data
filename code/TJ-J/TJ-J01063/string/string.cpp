#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	int a,b,c,d,e,f,g,s;
	int ans=0;
	cin>>a>>b>>c>>d>>e>>f>>g;
	s=b*c+d*e+f*g;
	do
	{
		s=s/10;
		if(s/10==s)
		cout<<"0";ans=0;break;
		if(s/10!=s)
		ans++;
	}while(s!=0);
	if(ans!=0)
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
