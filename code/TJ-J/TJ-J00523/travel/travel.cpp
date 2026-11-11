#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b,x,y;
int ans[5];
int main(){
	freopen("travel.in",read);
	freopen("travel.out",write);
	cin>>a>>x>>b>>y;
	if(a==b){
		ans[1]=1;
		if(x[0]==y[0]&&x[1]==y[1]){
			ans[2]=1;
			if(x[2]=='A'&&(y[2]=='B'||y[2]=='C')){
				ans[3]=1;
				if(y[2]=='B')ans[4]=1;
			}else if(x[2]=='B'&&(y[2]=='A'||y[2]=='C')){
				ans[3]=1,ans[4]=1;
			}else if(x[2]=='C'&&(y[2]=='A'||y[2]=='B')){
				ans[3]=1;
				if(y[2]=='B')ans[4]=1;
			}else if(x[2]=='D'&&y[2]=='F'){
				ans[3]=1,ans[4]=1;
			}else if(x[2]=='F'&&y[2]=='D'){
				ans[3]=1,ans[4]=1;
			}
		}
	}
	cout<<ans[1]<<ans[2]<<ans[3]<<ans[4];
	return 0;
}
