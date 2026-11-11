#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string c,s,cc,ss,ans;
    cin>>c>>cc>>s>>ss;
    ans[0]='0';
	ans[1]='0';
	ans[2]='0';
	ans[3]='0'; 
    if (c==s){
    	ans[0]='1';
	}
	if (cc[0]==ss[0] && cc[1]==ss[1]){
    	ans[1]='1';
	}
	if (cc[0]==ss[0] && cc[1]==ss[1]){
    	if((cc[2]=='A' || cc[2]=='B' || cc[2]=='C') && (ss[2]=='A' || ss[2]=='B' || ss[2]=='C')){
    		ans[2]='1';
		}
		if((cc[2]=='E' || cc[2]=='F' ) && (ss[2]=='E' || ss[2]=='F')){
    		ans[2]='1';
		}
	}
	if((cc[2]-ss[2]==1 || cc[2]-ss[2]==-1) && (!(((cc[2]=='C')&&(ss[2]=='D')) || ((cc[2]=='D')&&(ss[2]=='C'))))){
		ans[3]='1';
	}
	for(int i=0;i<=3;i++){
		cout<<ans[i];
	}
    return 0;
}

