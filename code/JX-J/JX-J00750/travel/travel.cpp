#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
            if(s1[0]!=s2[0]||s1[1]!=s2[1]){
                cout<<"1000";
                return 0;
            }else{
                char ch=s1[2],ss=s2[2];
                if(ch=='A'){
                    if(ss=='B'){
                        cout<<"1111";
                    }else if(ss=='C'){
                        cout<<"1110";
                    }else{
                        cout<<"1100";
                    }
                }else if(ch=='B'){
                    if(ss=='A'){
                        cout<<"1111";
                    }else if(ss=='C'){
                        cout<<"1111";
                    }else{
                        cout<<"1100";
                    }
                }else if(ch=='C'){
                    if(ss=='A'){
                        cout<<"1110";
                    }else if(ss=='B'){
                        cout<<"1111";
                    }else{
                        cout<<"1100";
                    }
                }else if(ch=='D'){
                    if(ss=='F'){
                        cout<<"1111";
                    }else{
                        cout<<"1100";
                    }
                }else if(ch=='F'){
                    if(ss=='D'){
                        cout<<"1111";
                    }else{
                        cout<<"1100";
                    }
                }
            }

    }else{
        cout<<"0000";
    }
    return 0;
}
