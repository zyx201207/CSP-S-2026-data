#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(a1[0]==b1[0] and a1[1]==b1[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char c=a1[2],d=b1[2];
	if(c=='E' and d=='D' or c=='D' and d=='E') cout<<1;
	else if(c!='E' and c!='D' and d!='E' and d!='D') cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	int f=0;
	if((c=='A' or c=='B' or c=='C') and (d=='D' or d=='E') or (d=='A' or d=='B' or d=='C') and (c=='D' or c=='E')){
		cout<<"0";
	}
	else{
		for(char i='A';i<='C';i++){
			for(char j='A';j<='C';j++){
				if(i==j) continue;
				if(c==i and d==j and (i==j+1 or i==j-1)) f=1;
			}
		}
		for(char i='D';i<='E';i++){
			for(char j='D';j<='E';j++){
				if(i==j) continue;
				if(c==i and d==j and (i==j+1 or i==j-1)) f=1;
			}
		}
		if(f==1) cout<<1;
		else cout<<0;
	}
	return 0;
}
