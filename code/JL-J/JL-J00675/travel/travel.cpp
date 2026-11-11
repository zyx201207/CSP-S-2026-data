#include <bits/stdc++.h>
using namespace std;
char ch[20];
int tmp=0;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=0;i<10;i++)
    {
        cin>>ch[i];

    }
    if(ch[0]==ch[5]&&ch[1]==ch[6])
    {
        cout<<1;
        if(ch[2]==ch[7]&&ch[3]==ch[8]) {
            cout<<1;
            if(ch[4]=='A'&&ch[9]=='B'||ch[4]=='A'&&ch[9]=='C'||ch[4]=='B'&&ch[9]=='A'||ch[4]=='B'&&ch[9]=='C'||ch[4]=='C'&&ch[9]=='A'||ch[4]=='C'&&ch[9]=='B'||ch[4]=='E'&&ch[9]=='F'||ch[4]=='F'&&ch[9]=='E')
            {
                cout<<1;
                if(ch[4]=='A'&&ch[9]=='B'||ch[4]=='B'&&ch[9]=='C'||ch[4]=='C'&&ch[9]=='B'||ch[4]=='B'&&ch[9]=='A'||ch[4]=='E'&&ch[9]=='F'||ch[4]=='F'&&ch[9]=='E') cout<<1;
                else cout<<0;
            }
            else {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else {
        cout<<"0000";
    }
    return 0;
}
