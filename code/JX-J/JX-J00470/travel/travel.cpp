#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("trauel.in","r",stdin);
    freopen("trauel.out","w",stdout);
    string x,y,nx,ny;
    cin>>x>>y>>nx>>ny;
    int a = x[0],b = x[1],c = nx[0],d = nx[1];
    if(a == c && b == d){
        cout<<'1';
    }else{
        cout<<'0'<<'0'<<'0'<<'0';
        return 0;
    }
    a = y[0],b = y[1],c = ny[0],d = ny[1];
    if(a == c && b == d){
        cout<<'1';
    }else{
        cout<<'0'<<'0'<<'0';
        return 0;
    }
    if(y[2] == 'D' || y[2] == 'F'){
        if(ny[2] == 'D' || ny[2] == 'F'){
            cout<<'1';
        }else{
            cout<<'0'<<'0';
            return 0;
        }
    }else{
        if(ny[2] == 'A' || ny[2] == 'B' || ny[2] == 'C'){
            cout<<'1';
        }else{
            cout<<'0'<<'0';
            return 0;
            }
    }
    if(y[2] == 'D' || y[2] == 'F'){
        if(ny[2] == 'D' || ny[2] == 'F'){
            cout<<'1';
            return 0;
        }else{
            cout<<'0';
            return 0;
        }
    }else{
        if(y[2] == 'B' || ny[2] == 'B'){
            cout<<'1';
            return 0;
        }else{
            cout<<'0';
            return 0;
        }
    }
    return 0;
}
