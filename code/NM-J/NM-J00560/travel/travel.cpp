#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool w1,w2,w3,w4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        w1=1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            w2=1;
            if((s1[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]<='F')){
                w3=1;
                if(s1[2]-s2[2]==-1||s1[2]-s2[2]==1){
                    w4=1;
                }

            }
        }
    }
    cout<<w1<<w2<<w3<<w4;


	return 0;
}
