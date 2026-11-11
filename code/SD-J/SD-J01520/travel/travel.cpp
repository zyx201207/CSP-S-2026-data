#include<bits/stdc++.h>
using namespace std;
char a1,a2,x1,x2,x3,b1,b2,y,y2,y3;
int ans[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>x1>>x2>>x3>>b1>>b2>>y>>y2>>y3;
	int s1=(a1-'0')*10+(a2-'0'),s2=(b1-'0')*10+(b2-'0');
	int c1=(x1-'0')*10+(x2-'0'),c2=(y-'0')*10+(y2-'0');
	if(s1==s2)
	 	ans[0]=1;
	if(c1==c2&&ans[0]==1)
		ans[1]=1;
	if((y3=='A'||y3=='B'||y3=='C')&&ans[1]==1)
		if(x3=='A'||x3=='B'||x3=='C')
			ans[2]=1;
	if((y3=='F'||y3=='E')&&ans[1]==1)
		if(x3=='F'||x3=='E')
			ans[2]=1;
	if(ans[2]==1&&(y3==x3+1||y3==x3-1))
		ans[3]=1;
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
}
