#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c){
        printf("0000");
    }
    else{
        if(b[0]!=d[0]||b[1]!=d[1]){
            printf("1000");
        }
        else{
            if(b[2]=='A'&&d[2]=='D'||b[2]=='A'&&d[2]=='F'||b[2]=='B'&&d[2]=='D'||b[2]=='B'&&d[2]=='F'||b[2]=='C'&&d[2]=='D'||b[2]=='C'&&d[2]=='F'){
                printf("1100");
            }
            else{
                if(abs(b[2]-d[2])!=1){
                    printf("1110");
                }
                else{
                    printf("1111");
                }
            }
        }
    }
    return 0;
}
