#include<bits/stdc++.h>
using namespace std;
int main(){
    int c1,c2;
    char s1[4];
    char s2[4];
    cin>>c1;
    for(int i=1;i<=3;i++){
    	cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
    	cin>>s2[i];
	}
    if(('s1[1]'!='s2[1]')&&('s1[2]'!='s2[2]')&&('s1[3]'!='s2[3]')){
        if(c1==c2){
            if(('s1[1]'=='s2[1]')&&('s1[2]'=='s2[2]')){
                if(('s1[3]'!='C'&&'s2[3]'!='D')&&('s2[3]'!='C'&&'s1[3]'!='D')){
                    if(('s1[3]'+1=='s2[3]')||('s1[3]'-1=='s2[3]')){
                        cout<<"1111";
                    }else{
                        cout<<"1110";
                    }
                }else{
                    cout<<"1100";
                }
            }else{
                cout<<"1000";
            }
        }else{
            cout<<"0000";
        }
    }
    return 0;
}