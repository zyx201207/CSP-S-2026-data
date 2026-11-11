#include<bits/stdc++.h>
using namespace std;
int getnum(char ch){
    if(ch<='C')return (int)ch;
    else return -(int)ch;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c)printf("0000");
    else{
        printf("1");
        if(b[0]!=d[0] or b[1]!=d[1])printf("000");
        else{
            printf("1");
            int x=getnum(b[2]),y=getnum(d[2]);
            if(x*y<0)printf("00");
            else{
                printf("1");
                if(abs(x-y)!=1)printf("0");
                else printf("1");
            }
        }
    }
    return 0;
}
