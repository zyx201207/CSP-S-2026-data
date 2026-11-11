#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a,b,c,d,e,f,g,h,i,j;
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
    if(a==f and b==g){
        if(c==h and d==i){
            int x=e-'A';
            int y=j-'A';
            if((x<3 and y<3) or (x>2 and y>2)){
                if(abs(x-y)==1){
                    cout<<"1111";
                }
                else cout<<"1110";
            }
            else cout<<"1100";
        }
        else cout<<"1000";
    }
    else cout<<"0000";
    return 0;
}
