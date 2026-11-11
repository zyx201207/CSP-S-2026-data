#include<bits/stdc++.h>;
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a;
    string b;
    string c;
    string d;
    cin>>a>>b>>c>>d;
    int k=0,j=0;
    if(a.size()==c.size()){
        for(int i=0;i<a.size();i++){
            if(a[i]==c[i]){
                k++;
            }
        }
        if(k==a.size()){
            cout<<"1";
        }
        else{
            cout<<"0000";
            return 0;
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
    int t=b.size()-1;
    for(int i=0;i<t;i++){
        if(b[i]==d[i]){
            j++;
        }
    }
    if(j==t){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if(b[t]=='E'||b[t]=='F'&&d[t]=='E'||d[t]=='F'){
        cout<<"11";
        return 0;
    }
    else if(b[t]=='A'||b[t]=='B'||b[t]=='C'&&d[t]=='A'||d[t]=='B'||d[t]=='C'){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if(b[t]=='A'&&d[t]=='B'||b[t]=='B'&&d[t]=='A'||b[t]=='B'&&d[t]=='C'||b[t]=='C'&&d[t]=='B'){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
