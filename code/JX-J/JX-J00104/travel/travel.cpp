#include <iostream>
using namespace std;
int c1,s1r,c2,s2r;
char s1c,s2c;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1r>>s1c>>c2>>s2r>>s2c;
    bool tmp[5]={0};
    tmp[s1c-'A']=true;
    tmp[s2c-'A']=true;
    cout<<int(c1==c2);
    cout<<int(c1==c2 && s1r==s2r);
    cout<<int(c1==c2 && s1r==s2r && ((tmp[3] && tmp[4]) || (!tmp[3] && !tmp[4])));
    cout<<int(c1==c2 && s1r==s2r && ((tmp[3] && tmp[4]) || (tmp[0] && tmp[1]) || (tmp[1] && tmp[2])));
    return 0;
}
