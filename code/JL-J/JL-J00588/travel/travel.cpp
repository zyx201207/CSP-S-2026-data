#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    string b,d,p[5],q[5];
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<b.size();i++){
        p[i]=b[i];
    }
    for(int i=0;i<d.size();i++){
        q[i]=d[i];
    }
    for(int i=1;i<=2;i++){
        if(p[i]==q[i]){
            cout<<"1";
            break;
        }else{
            cout<<"000";
            return 0;
        }
    }
    if(p[3]=="A"&&q[3]=="B"||p[3]=="A"&&q[3]=="C"||p[3]=="B"&&q[3]=="C"){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if(p[3]=="A"&&q[3]=="B"||p[3]=="B"&&q[3]=="C"||p[3]=="C"&&q[3]=="D"||p[3]=="D"&&q[3]=="F"){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}

