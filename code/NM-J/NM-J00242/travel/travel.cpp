#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string s,c,s1,c1;
	int a,b;
    cin>>s>>c>>s1>>c1;
    a=int(c[2])%65;
    b=int(c1[2])%65;
    if(s==s1){
        cout<<"1";
        if(c[0]!=c1[0]){
            cout<<"000";
            return 0;
        }
        else if(c[1]!=c1[1]){
            cout<<"000";
            return 0;
        }
        else{
            cout<<"1";
            if(a<=2&&b>2){
                cout<<"00";
                return 0;
            }
            else if(b<=2&&a>2){
                cout<<"00";
                return 0;
            }
            else{
                cout<<"1";
                if(a<=2){
                    if(a==2&&b==1){
                        cout<<"1";
                        return 0;
                    }
                    else if(a==1){
                        cout<<"1";
                        return 0;
                    }
                    else if(a==0&&b==1){
                        cout<<"1";
                        return 0;
                    }
                    else {
                        cout<<"0";
                        return 0;
                    }
                }
                else{
                    cout<<"1";
                    return 0;
                }
            }
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
