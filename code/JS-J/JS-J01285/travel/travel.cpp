#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    bool _1=(a==c);
    bool _2=(b[0]==d[0]&&b[1]==d[1]);
    bool _3=(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F');
    bool _4=(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'&&abs(b[2]-d[2])==1)||b[2]=='D'&&d[2]=='F'||d[2]=='D'&&b[2]=='F';
    cout<<(_1);
    cout<<(_1&&_2);
    cout<<(_1&&_2&&_3);
    cout<<(_1&&_2&&_3&&_4);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//sto CCF orz ccw.site chat.deepseek.com
//ygg luogu:yjh_114514 ACGO:2433437 bilibili:xiao yan bu yan ya
//X X XXX  X X XXX
//ciallo~
//phigros MC BA
//love CCF
