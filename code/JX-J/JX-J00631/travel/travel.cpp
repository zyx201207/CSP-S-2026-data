#include <bits/stdc++.h>

using namespace std;

struct P{
    char train[3], sit[4];
};

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    P r, x;
    int cnt=0;
    cin>>r.train>>r.sit>>x.train>>x.sit;
    //cout<<'"'<<r.train<<'"'<<r.sit<<'"'<<x.train<<'"'<<x.sit<<endl;
    if(r.train[0]==x.train[0]&&r.train[1]==x.train[1]){
        cnt++;
        if(r.sit[0]==x.sit[0]&&r.sit[1]==x.sit[1]){
            cnt++;
            if((r.sit[2]<='C'&&x.sit[2]<='C') || (r.sit[2]>='D'&&x.sit[2]>='D')){
                cnt++;
                if(abs(r.sit[2]-x.sit[2])==1) cnt++;
            }
        }
    }
    for(int i=0; i<cnt; i++) cout<<1;
    for(int i=cnt; i<4; i++) cout<<0;
    return 0;
}
