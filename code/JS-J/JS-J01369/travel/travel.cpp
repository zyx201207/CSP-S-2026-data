#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char ch;
    char x,y;
    int a1=0,b1=0,a2=0,b2=0;

    ch=getchar();
    a1+=ch-48;
    ch=getchar();
    a1=a1*10+ch-48;
    ch=getchar();
    ch=getchar();
    a2+=ch-48;
    ch=getchar();
    a2=a2*10+ch-48;
    x=getchar();
    ch=getchar();
    if(x=='F')x='E';

    ch=getchar();
    b1+=ch-48;
    ch=getchar();
    b1=b1*10+ch-48;
    ch=getchar();
    ch=getchar();
    b2+=ch-48;
    ch=getchar();
    b2=b2*10+ch-48;
    y=getchar();
    if(y=='F')y='E';

    if(a1==b1){
        cout<<1;
        if(a2==b2){
            cout<<1;
            if(x>y)swap(x,y);
            if((x=='D'&&y=='E')||(x!='D'&&y!='D')){
                cout<<1;
                if((y-x)==1)cout<<1<<"\n";
                else cout<<"0\n";
            }
            else{
                cout<<"00\n";
            }
        }
        else{
            cout<<"000\n";
        }
    }
    else{
        cout<<"0000\n";
    }
    return 0;
}