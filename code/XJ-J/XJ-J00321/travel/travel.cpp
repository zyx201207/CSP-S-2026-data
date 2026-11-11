#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
char leftt[]={'0','A','B','C'},rightt[]={'0','D','F'};
bool find(char c1,char c2){
	bool b1=false,b2=false,b3=false,b4=false;
	for(int i=1;i<=3;i++){
		if(leftt[i]==c1)  {
			b1=true;
		}
		if(leftt[i]==c2)  {
			b2=true;
		}
	}
	for(int i=1;i<=2;i++){
		if(rightt[i]==c1)  {
			b3=true;
		}
		if(rightt[i]==c2)  {
			b4=true;
		}
	}
	return (b1&&b2)||(b3&&b4);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>a>>b>>c>>d;
    if(a==c){
    	cout<<1;
        if(b[0]==d[0]&&b[1]==d[1]){
    	    cout<<1;
    	    if(find(b[2],d[2])){
    	    	cout<<1;
    	    	if(abs(b[2]-d[2])<=1)  {
    	    		cout<<1;
				}
    	    	else {
    	    		cout<<0;
				}
			}
			else {
				cout<<"00";
			}
	    }
	    else {
	    	cout<<"000";
		}
	}
    else {
    	cout<<"0000";
	}	
    return 0;
}