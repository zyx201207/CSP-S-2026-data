#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
bool ans[5];
bool sidecheck(string x,string y){
    return (((x[2]=='A' && y[2]=='B') || (x[2]=='A' && y[2]=='C')) ||
             (x[2]=='B' && y[2]=='C') || (x[2]=='D' && y[2]=='F'));
}
bool nextcheck(string x,string y){
    return ((x[2]=='A' && y[2]=='B') || (x[2]=='B' && y[2]=='C') ||
             x[2]=='D' && y[2]=='F');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
        ans[1]=1;
	}
	if(s1.substr(0,2)==s2.substr(0,2)){
        if(ans[1]) ans[2]=1;
	}
	if(sidecheck(s1,s2) || sidecheck(s2,s1)){
        if(ans[2]) ans[3]=1;
	}
	if(nextcheck(s1,s2) || nextcheck(s2,s1)){
        if(ans[3]) ans[4]=1;
	}
	for(int i=1;i<=4;i++){
        cout<<ans[i];
	}
	cout<<"\n";
	return 0;
}

