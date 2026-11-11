include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,c,d;
    char e,f;
    cin >> a >> e >> b >> f;
    if(a == b){
        cout << 1;
    }
    eise{
        cout << 0 << 0 << 0 << 0;
        return 0;
    }
    if(e - 1 == f || e + 1 == f || e - 2 == f || e + 2 == f || e - 3 == f || e + 3 == f || e - 4 == f || e + 4 == f || e - 5 == f || e + 5 == f){
        cout << 1;
    }
    else{
        cout << 0 << 0 << 0;
        return 0;
    }
    if(e - 1 == f || e + 1 == f){
        if(e - 2 == f || e + 2 == f){
            cout << 1;
        }
    }
    else{
        cout << 0 << 0;
        return 0;
    }
    if(e - 1 == f || e + 1 == f){
        cout << 1;
    }
    return 0;
}
