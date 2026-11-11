#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a=0,b=0,c=0,d=0,p=0,p1=0,p2=0,p3=0;
    char b1=0,d1=0;
    cin>>a>>b>>b1>>c>>d>>d1;
    if(a==c){
        p=1;
        if(b==d){
            p1=1;
            if(('A'<=b1 and b1<='C' and 'A'<=d1 and d1<='C') or ('D'<=b1 and b1<='F' and 'D'<=d1 and d1<='F')){
                    p2=1;
                    if((b1=='A' and d1=='B') or (b1=='B' and d1=='A') or (b1=='B' and d1=='C') or (b1=='D' and d1=='B') or (b1=='D' and d1=='F') or (b1=='F' and d1=='D')){
                        p3=1;
                        cout<<p<<p1<<p2<<p3;
                    }
                    else{
                        cout<<p<<p1<<p2<<p3;
                    }
            }
            else{
                cout<<p<<p1<<p2<<p3;
            }
        }
        else{
            cout<<p<<p1<<p2<<p3;
        }
    }
    else{
        cout<<p<<p1<<p2<<p3;
    }
    return 0;
    //AB BA BC CB DF FD
}
