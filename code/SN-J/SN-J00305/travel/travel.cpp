#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ans[6];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	ans[1]=1;
	if(b[0]==d[0]&&b[1]==d[1])
	ans[2]=1;
	if(ans[1]==1&&ans[2]==1){
	if(b[2]=='D'||b[2]=='E')
	{
		if(d[2]=='D'||d[2]=='E')
		{
			ans[3]=1;
		}
	}
	else{
		if(d[2]=='A'||d[2]=='B'||d[2]=='C')
		{
			ans[3]=1;
		}
	}
	if(ans[3]==1){
		if((d[2]==b[2]+1||d[2]==b[2]-1)){
			ans[4]=1;
		}
	}
}
	if(ans[1]==0){
		ans[2]=0;
		ans[3]=0;
		ans[4]=0;
	}
	cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
	
	return 0;
}


 
