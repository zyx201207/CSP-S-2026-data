#include<bits/stdc++.h>
using namespace std;
string s1,s2,a1,a2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s1>>a1>>s2>>a2;
    if(s1 != s2){
        cout<<"0000"<<endl;
        return 0;
    }
    else{
        cout<<"1";
    }
    if((a2[0] == a1[0]) && (a2[1] == a1[1])){
        cout<<"1";
        char a = a1[2],b = a2[2];
        if(a == 'A' || a == 'B' || a == 'C'){
            if(b == 'F' || b == 'D'){
                cout<<"00"<<endl;
                return 0;
            }
        }
        if(a == 'F' || a == 'D'){
            if(b == 'A' || b == 'B' || b == 'C'){
                cout<<"00"<<endl;
                return 0;
            }
        }
        cout<<"1";
        if(a=='A'){
            if(b == 'B')cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
        else if(a == 'B'){
            if(b == 'A' || b == 'C')cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
        else if(a=='C'){
            if(b == 'B')cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
        else if(a=='D'){
            if(b == 'F')cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
        else if(a=='F'){
            if(b == 'D')cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
    }
    else{
        cout<<"000"<<endl;
        return 0;
    }

    return 0;
}
