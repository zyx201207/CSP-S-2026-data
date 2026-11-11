#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
        cout<<"0000";
	}
	else{
        cout<<"1";
        int temp1=(s1[0]-=48)*10+(s1[1]-=48);
        int temp2=(s2[0]-=48)*10+(s2[1]-=48);
        if(temp1!=temp2){
            cout<<"000";
        }
        else{
            cout<<"1";
            if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]=='D'&&s2[2]=='F')&&(s1[2]=='F'&&s2[2]=='D'))){
                cout<<"1";
                if(abs(s1[2]-s2[2])==1){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
	}
	return 0;
}
