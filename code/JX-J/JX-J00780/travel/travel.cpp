#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    string x;
    string y;

    cin>>n>>x>>y>>m;
    if(n!=m){
        cout<<"0000";
        return 0;
    }else{
        cout<<'1';
    }
    if(x[0]!=y[0]){
        cout<<"00";
    }else{
        cout<<'1';
        if(x[1]=='F'||x[1]=='D'){
            if(y[1]=='F'||y[1]=='D'){
                cout<<'1';
            }else{
                cout<<'0';
            }
        }else{
            if(y[1]!='F'&&y[1]!='D'){
                cout<<'1';
            }else{
                cout<<'0';
            }
        }
    }
    int f=x[1];
    int k=y[1];
    if(f+1==k||f-1==k){
        k=x[2];
        f=y[2];
        if(k+1==f||k-1==f||k==f){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        cout<<0;
    }
    
    return 0;
    fclose(stdin);
    fclose(stdout);
}
