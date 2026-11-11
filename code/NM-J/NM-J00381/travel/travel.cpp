#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);

    char c1[2],s1[3],c2[2],s2[3],a[4]={'0','0','0','0'};
    cin>>c1>>s1>>c2>>s2;
    if(c1[1]==c2[1] and c1[2]==c2[2]){
        a[0]='1';
    }
    else{
    	cout<<a;
    	return 0;
	}
	if(s1[0]==s2[0] and s1[1]==s2[1]){
        a[1]='1';
	}
	else{
        cout<<a;
        return 0;
	}
	if(s1[2]=='A' or s1[2]=='B' or s1[2]=='C'){
	    if(s2[2]=='D' or s2[2]=='F'){
            cout<<a;
            return 0;
	    }
	    else{
            a[2]=='1';
	    }
	    }
    else if(s2[2]=='D' or s2[2]=='F'){
        a[2]=='1';
    }
    else{
        cout<<a;
        return 0;
    }
    if(s1[2]=='A' or s1[2]=='C'){
        if(s2[2]=='B'){
            a[3]=='1';
        }
        else{
            cout<<a;
            return 0;
        }
    }
    else if(s1[2]=='B'){
        if(s2[2]=='A' or s2[2]=='C'){
            a[3]=='1';
        }
        else{
            cout<<a;
            return 0;
        }
    }
    else if(s2[2]=='D' or s2[2]=='F'){
        a[3]=='1';
    }
    else{
        cout<<a;
        return 0;
    }
    cout<<a;
    return 0;
}
