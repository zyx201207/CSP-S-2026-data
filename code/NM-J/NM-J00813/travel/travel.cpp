#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int a=0,b=0;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        a++;
        for(int i=0;i<2;i++){
            if(s1[i] == s2[i]){
                b++;
                if(b==2){
                    a++;
                    if(s1[2] == 'C' && s2[2] == 'D'){
                        break;
                    }
                    else if(s1[2] == 'D' && s2[2] == 'C'){
                        break;
                    }
                    else{
                        a++;
                        if(s1[2] + 1 ==s2[2] || s1[2] - 1 ==s2[2]){
                            a++;
                        }
                    }
                }
            }
        }
    }
    if(a==0) cout << "0000";
    if(a==1) cout << "1000";
    if(a==2) cout << "1100";
    if(a==3) cout << "1110";
    if(a==4) cout << "1111";
    return 0;}
