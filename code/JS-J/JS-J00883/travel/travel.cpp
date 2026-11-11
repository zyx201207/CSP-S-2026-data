#include<bits/stdc++.h>
using namespace std;
int a,b;
char c[5],ch[5];
int q[12];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>c[1]>>c[2]>>c[3];
    cin>>b>>ch[1]>>ch[2]>>ch[3];
    if(a==b)q[1]=1;
    if(q[1]&&c[1]==ch[1]&&c[2]==ch[2])
       q[2]=1;
    if(q[2]&&((c[3]<='C'&&ch[3]<='C')||(c[3]>='E'&&ch[3]>='E')))
        q[3]=1;
    if(q[3]&&abs(int(c[3])-int(ch[3]))==1)
        q[4]=1;
    cout<<q[1]<<q[2]<<q[3]<<q[4];
    return 0;
}//
//--------quzhushi
