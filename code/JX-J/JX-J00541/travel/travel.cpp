#include<bits/stdc++.h>
using namespace std;
string a,b,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a>>b>>a2>>b2;
    if(a==a2){
        cout<<"1";
        char yi=b[0],er=b[1],san=b[2];
        char yi1=b2[0],er1=b2[1],san1=b2[2];
        if(yi==yi1&&er==er1){
            cout<<"1";
            if(((san=='A'||san=='B'||san=='C')&&(san1=='A'||san1=='B'||san1=='C'))||((san=='D'||san=='F')&&(san1=='D'||san1=='F'))){
                cout<<"1";
                if((san=='A'&&san1=='B')||(san=='B'&&(san1=='A'||san1=='C'))||(san=='C'&&san1=='B')||(san=='D'&&san1=='F')||(san=='F'&&san1=='D')){
                    cout<<"1";
                }
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
	return 0;
}
