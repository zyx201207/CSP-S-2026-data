#include<bits/stdc++.h>
using namespace std;
int a[5] = {0,0,0,0,0};
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    string rc;
    string rs;
    string xc;
    string xs;

    cin >> rc >> rs >> xc >> xs;
    if(rc[0] == xc[0]&&rc[1] == xc[1]){
        a[0] = 1;
    }

    if(rs[0] == xs[0]&&rs[1] == xs[1]){
        a[1] = 1;
    }

    if(rs[2] == 'A'){
        if(xs[2] == 'B'){
            a[2] = 1;
            a[3] = 1;
        }
        else if(xs[2] == 'c') a[2] = 1;
    }

    if(rs[2] =='B'){
        if(xs[2] == 'A'||xs[2] == 'C'){
            a[2] = 1;
            a[3] = 1;
        }
    }
    if(rs[2] == 'C'){
        if(xs[2] == 'B'){
            a[2] = 1;
            a[3] = 1;
        }
        else if(xs[2] == 'A') a[2] = 1;
    }

    if(rs[2] == 'D'){
        if(xs[2] == 'F'){
            a[2] = 1;
            a[3] = 1;
        }
    }
    if(rs[2] == 'F'){
        if(xs[2] == 'D'){
            a[2] = 1;
            a[3] = 1;
        }
    }
    for(int i = 0;i <= 3;i++){
        cout << a[i];
    }
    return 0;
}
