#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    if(c1!=c3){
        cout<<"0000"<<'\n';
        return 0;
    }
    cout<<1;
    if(c2[0]!=c4[0]||c2[1]!=c4[1]){
        cout<<"000"<<'\n';
        return 0;
    }
    cout<<1;
    if(c2[2]=='A'){
        if(c4[2]=='D'){
            cout<<"00"<<'\n';
            return 0;
        }
        else if(c4[2]=='F'){
            cout<<"00"<<'\n';
            return 0;
        }
    }
    else if(c2[2]=='B'){
        if(c4[2]=='D'){
            cout<<"00"<<'\n';
            return 0;
        }
        else if(c4[2]=='F'){
            cout<<"00"<<'\n';
            return 0;
        }
    }
    else if(c2[2]=='C'){
        if(c4[2]=='D'){
            cout<<"00"<<'\n';
            return 0;
        }
        else if(c4[2]=='F'){
            cout<<"00"<<'\n';
            return 0;
        }
    }
    else if(c2[2]=='D'){
        if(c4[2]=='A'){
            cout<<"00"<<'\n';
            return 0;
        }
        else if(c4[2]=='B'){
            cout<<"00"<<'\n';
            return 0;
        }
        else if(c4[2]=='C'){
            cout<<"00"<<'\n';
            return 0;
        }
    }
    else if(c2[2]=='F'){
        if(c4[2]=='A'){
            cout<<"00"<<'\n';
            return 0;
        }
        else if(c4[2]=='B'){
            cout<<"00"<<'\n';
            return 0;
        }
        else if(c4[2]=='C'){
            cout<<"00"<<'\n';
            return 0;
        }
    }
    cout<<1;
    if(c2[2]=='A'&&c4[2]=='C'){
        cout<<0<<'\n';
        return 0;
    }
    else if(c2[2]=='C'&&c4[2]=='A'){
        cout<<0<<'\n';
        return 0;
    }
    cout<<1<<'\n';
    return 0;
}
