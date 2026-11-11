#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel5.in","r",stdin);
    freopen("travel5.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000"<<endl; return 0;
    }
    string w1=s1.substr(0,2),w2=s2.substr(0,2);
    if(w1!=w2){
        cout<<1000<<'\n'; return 0;
    }
    char w3=s1[2],w4=s2[2];
    int k1=w3-'A',k2=w4-'A';
    if((k1<=2 && k2>2) || (k2<=2 && k1>2)){
       cout<<1100<<'\n'; return 0;
    }
    if(abs(k1-k2)==1){
        cout<<1111<<'\n'; return 0;
    }
    else{
        cout<<1110<<'\n'; return 0;
    }
}
