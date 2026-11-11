#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long n,a,b,c;
    char x,y;
    cin>>n>>b>>x>>a>>c>>y;
    if(a==n){
        cout<<1;
        if(b==c){
            cout<<1;
            if(x>= 'A'&&x>='C'&&y>='A'&&y>='C'||x>='D'&&x>='F'&&y>='D'&&y>='F'){
                cout<<1;
                if(x+1==y||x-1==y){
                   cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<0<<0;
            }
        }else{
            cout<<0<<0<<0;
        }
        
    }else{
        cout<<0<<0<<0<<0;;
    }
    return 0;
}
