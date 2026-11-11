#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int ans1=(a==c),ans2=ans1&&(b[0]+b[1]==d[0]+d[1]),ans3=ans2&&(b[2]>='D'&&d[2]>='D'||b[2]<'D'&&d[2]<'D'),ans4=ans3&&(d[2]==b[2]+1||d[2]==b[2]-1);
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
