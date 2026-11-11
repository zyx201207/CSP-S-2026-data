#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int q,w,e,r;
    char n,m;
    cin >>q>>w>>n>>e>>r>>m;
    if(q==e){
        cout<<"1";
    }
    if(q!=e){
        cout <<"0"<<"0"<<"0"<<"0";
        return 0;
    }
    if(w==r){
        cout <<"1";
    }
    if(w!=r){
        cout <<"0"<<"0"<<"0";
        return 0;
    }
    if(n=='A'||n=='B'||n=='C'){
            if(m=='D'||m=='F'){
                 cout <<"0"<<"0";
                 return 0;
            }

    }
    if(n=='A'||n=='B'||n=='C'){
            if(m=='A'||m=='B'||m=='C'){
                 cout <<"1";
                 if(n=='A'||n=='C'){
                    if(m=='C'||m=='A'){
                        cout << "0";
                        return 0;
                    }
                 }
                 cout <<"1";
                 return 0;
    }

    }
    if(n=='D'||n=='F'){
            if(m=='D'||m=='F'){
                 cout <<"1"<<"1";
                 return 0;
            }

    }





return 0;
}
