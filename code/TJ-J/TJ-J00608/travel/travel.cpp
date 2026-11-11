#include<bits/stdc++.h>
using namespace std;
int
int main(){
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    int c1;
    int s1;
    int c2;
    int s2;

    cin >> c1 >> s1 >> c2 >> s2;
    if(c1=c2){
        if(s1=s2){
            cout << 1111;
        }

    }
    else if(c1=c2){
            if(s1!=s2){
                cout << 1100;
            }
    }
    else if(c1!=c2){
        if(s1=s2){
            cout <<0011;
        }
    }
    else{
        cout <<0000;
    }

    return 0;



    }



