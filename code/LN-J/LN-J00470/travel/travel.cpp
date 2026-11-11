#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2;
    cin>>b1>>b2;
    int xianga=(a1[0]-'0')*10+(a1[1]-'0');
    int xiangb=(b1[0]-'0')*10+(b1[1]-'0');
    if(xianga!=xiangb) cout<<"0000"<<endl;
    else
    {
        cout<<"1";
        int paia=(a2[0]-'0')*10+(a2[1]-'0');
        int paib=(b2[0]-'0')*10+(b2[1]-'0');
        int ca=a2[2]-'A',cb=b2[2]-'A';
        if(paia!=paib) cout<<"0";
        else cout<<"1";

        if((ca==0&&(cb==1||cb==2))||(ca==1&&(cb==0&&cb==2))||(ca==2&&(cb==1||cb==0))||(ca==3&&cb==5)||(ca==5&&cb==3)) cout<<"1";
        else cout<<"0";

        if((abs(paia-paib)==1&&ca==cb)||(((ca==0&&cb==1)||(ca==1&&(cb==0||cb==2))||(ca==2&&cb==1)||(ca==3&&cb==5)||(ca==5&&cb==3))&&paia==paib))
            cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
    return 0;
}
