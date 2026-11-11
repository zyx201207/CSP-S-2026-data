#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int a,b;
	string c,d,s,y;
	cin>>a>>s>>b>>y;
	
	if(a==b){
		cout<<1;
		if(s[0]==y[0]&&s[1]==y[1]){
			cout<<1;
			if(s[2]=='A'||s[2]=='B'||s[2]=='C'&&y[2]=='A'||y[2]=='B'||y[2]=='C'||s[2]=='D'||s[2]=='E'&&y[2]=='D'||y[2]=='E'){
            cout<<1;
            if(s[2]=='A'&&y[2]=='B'||s[2]=='B'&&y[2]=='C'||s[2]=='B'&&y[2]=='A'||s[2]=='C'&&y[2]=='B'||s[2]=='D'&&y[2]=='E'||y[2]=='D'&&s[2]=='E')
                cout<<1;
                else{
                    cout<<0;
                }
        }
        else
        cout<<"00";
		}
		else
		cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
}
