#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            char a=s1[2],b=s2[2];
            if(a=='A'&&b=='B')cout<<"11";
            if(a=='A'&&b=='C')cout<<"10";
            if(a=='A'&&b=='D')cout<<"00";
            if(a=='A'&&b=='F')cout<<"00";
            if(a=='B'&&b=='C')cout<<"11";
            if(a=='B'&&b=='D')cout<<"00";
            if(a=='B'&&b=='F')cout<<"00";
            if(a=='C'&&b=='D')cout<<"00";
            if(a=='C'&&b=='F')cout<<"00";
            if(a=='D'&&b=='F')cout<<"11";
            
            if(b=='A'&&a=='B')cout<<"11";
            if(b=='A'&&a=='C')cout<<"10";
            if(b=='A'&&a=='D')cout<<"00";
            if(b=='A'&&a=='F')cout<<"00";
            if(b=='B'&&a=='C')cout<<"11";
            if(b=='B'&&a=='D')cout<<"00";
            if(b=='B'&&a=='F')cout<<"00";
            if(b=='C'&&a=='D')cout<<"00";
            if(b=='C'&&a=='F')cout<<"00";
            if(b=='D'&&a=='F')cout<<"11";
        }else{
            cout<<"000";
            return 0;
        }
	}else{
        cout<<"0000";
        return 0;
	}
	return 0;
}
