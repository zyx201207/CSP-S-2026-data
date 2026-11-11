#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ans[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			ans[2]=1;
			if((s1[2]<='C'&&s2[2]<='C')){
				ans[3]=1;
				if(s1[2]=='B'||s2[2]=='B')ans[4]=1;
			}
			else if(s1[2]>'C'&&s2[2]>'C')ans[3]=ans[4]=1;
		}
	}
	for(int i=1;i<=4;i++)cout<<ans[i];
	return 0;
}