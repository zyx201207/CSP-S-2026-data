#include<bits/stdc++.h>
using namespace std;
int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    char A,B,C,D,F;
    if(c1==c2){
    	if(s1[2]==s2[2]){
    		if(s1[3]==A&&s2[3]==B||s1[3]==B&&s2[3]==C||s1[3]==D&&s2[3]==F||s1[3]==B&&s2[3]==A||s1[3]==C&&s2[3]==B||s1[3]==F&&s2[3]==D){
    			cout<<"1111";
			}
			else if(s1[3]==A&&s2[3]==C||s1[3]==C&&s2[3]==A){
				cout<<"1110";
			}
			else{
				cout<<"1100";
			}
		}
		else{
    		cout<<"1000";
		}
	}

	else{
		cout<<"0000";
	}
    return 0;
}
