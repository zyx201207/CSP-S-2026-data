#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
signed main(){
    m["A"]=0;
    m["B"]=0;
    m["C"]=0;
    m["D"]=1;
    m["E"]=1;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(stoi(a)!=stoi(c)){
        cout<<"0000"<<endl;
        return 0;
    }
    cout<<1;
    if(stoi(b.substr(0,2))!=stoi(d.substr(0,2))){
        cout<<"000"<<endl;
        return 0;
    }
    cout<<1;
    string x=b.substr(2),y=d.substr(2);
    if(m[x]!=m[y]){
        cout<<"00"<<endl;
        return 0;
    }
    cout<<1;
    int xx=x[0]-'A',yy=y[0]-'A';
    if(abs(xx-yy)==1){
        cout<<1<<endl;
    }
    else{
        cout<<0;
    }
}
