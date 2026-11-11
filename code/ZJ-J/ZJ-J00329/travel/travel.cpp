#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            bool b1,b2;
            int i1=s1[2]-'A'+1,i2=s2[2]-'A'+1;
            if(s1[2]=='F'){
            	i1=5;
			}
			if(s2[2]=='F'){
				i2=5;
			}
			
            if((i1<=3)&&(i2<=3)||(i1>=4)&&(i1>=4)){
				cout<<"1";
				if(abs(i1-i2)==1){
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
