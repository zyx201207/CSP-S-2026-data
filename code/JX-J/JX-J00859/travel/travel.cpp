#include<bits/stdc++.h>
using namespace std;
int a,b,f;
string n,m;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>n>>b>>m;
    int c=(n[0]-48)*10+(n[1]-48);
    int d=(m[0]-48)*10+(m[1]-48);
    n=n[2];
    m=m[2];
    if(a==b){
        cout<<1;
        f++;
        if(c==d){
            cout<<1;
            f++;
            if(((n=="A"||n=="B"||n=="C")&&(m=="A"||m=="B"||m=="C")) || ((n=="D"||n=="F")&&(m=="D"||m=="F"))){
                cout<<1;
                f++;
                if((n=="A"&&m=="B")||(n=="B"&&m=="C")||(n=="D"&&m=="F")||(n=="B"&&m=="A")||(n=="C"&&m=="B")||(n=="F"&&m=="D")){
                    cout<<1;
                    f++;
                }
            }
        }
    }
    for(int i=1;i<=4-f;i++){
        cout<<0;
    }

    return 0;
}
