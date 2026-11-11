#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    if(a==b){
        cout<<1<<endl;
        if(c[0]==d[0]&&c[1]==d[1]){
        cout<<1<<endl;
        if((c[2]=='A'||c[2]=='B'||c[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){
            cout<<1<<endl;
            if(abs(c[2]-d[2])==1){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }else if((c[2]=='D'||c[2]=='E')&&(d[2]=='D'||d[2]=='E')){
            cout<<1<<endl;
            if(abs(c[2]-d[2])==1){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
        }else{
            cout<<0<<endl;
            cout<<0<<endl;
        }
    }else{
        cout<<0<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
    }
    }else{
        cout<<0<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
        cout<<0<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

