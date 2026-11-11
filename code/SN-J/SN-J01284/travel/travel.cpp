#include<bits/stdc++.h>
using namespace std;
int ans[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string a,b;
	cin>>n>>a>>m>>b;
	if(n==m){
		ans[0]=1;
		if(((a[0]-'0')*10+(a[1]-'0'))==((b[0]-'0')*10+(b[1]-'0'))){
			ans[1]=1;
			if(((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C'))||((a[2]=='F'||a[2]=='D')&&(b[2]=='F'||b[2]=='D'))){
				ans[2]=1;
				if((a[2]=='A'&&b[2]=='B')||(b[2]=='A'&&a[2]=='B')||(b[2]=='B'&&a[2]=='C')||(a[2]=='B'&&b[2]=='C')||(b[2]=='D'&&a[2]=='F')||(a[2]=='D'&&b[2]=='F')) ans[3]=1;
			} 
		} 
	} 
	cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
	return 0;
}
