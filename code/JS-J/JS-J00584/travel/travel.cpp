#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int b1=b[2]-'A';
	int d1=d[2]-'A';
	if(a==c){
		cout<<'1';
		if(b[0]==d[0] && b[1]==d[1]){
		    cout<<'1';
		    if((b1<3 && d1<3) || (b1>3 && d1>3)){
                cout<<'1';
                if(abs(b1-d1)==1 || (b1==3 && d1==5) || (b1==5 && d1==3)){
                    cout<<1;
                }
                else{
                    cout<<"0";
                }
		    }
		    else{
                cout<<"00";
                return 0;
		    }
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
	    cout<<"0000";
	    return 0;
	}

}
