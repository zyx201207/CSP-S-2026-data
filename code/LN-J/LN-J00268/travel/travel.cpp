#include<bits/stdc++.h>
using namespace std;
const int R = 1010;
bool tyc(char a,char b){
    if(a < b){
        swap(a,b);
    }
    if(a == 'F'){
        if(b == 'D'){
            return true;
        }else{
            return false;
        }
    }
    if(a <= 'C'){
        return true;
    }else{
        return false;
    }
}
bool btw(char a,char b){
    if(a < b){
        swap(a,b);
    }
    if(a == 'F'){
        if(b == 'D'){
            return true;
        }else{
            return false;
        }
    }
    if(a == 'B' || b == 'B'){
        return true;
    }else{
        return false;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m,p,q;
    char c1[11],c2[11],l,t;
    cin>>n>>c1>>m>>c2;
    p = (c1[0]-'0')*10 + (c1[1]-'0');
    q = (c2[0]-'0')*10 + (c2[1]-'0');
    l = c1[2];t = c2[2];
    if(n == m){
        cout<<"1";
        if(p == q){
            cout<<"1";
            if(tyc(l,t)){
                cout<<"1";
                if(btw(l,t)){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
