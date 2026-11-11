#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    bool a[4]={0,0,0,0};
    pair<int,string> c;
    pair<int,string> s;
    cin>>c.first>>c.second>>s.first>>s.second;
    if(c.first==s.first){
        a[0]=1;
        if(c.second[0]==s.second[0]&&c.second[1]==s.second[1]){
            a[1]=1;
            if(c.second[2]<='C'&&s.second[2]<='C'||c.second[2]>='C'&&s.second[2]>='C'&&c.second[2]<='F'&&s.second[2]<='F'){a[2]=1;}
        }
    }
    if(c.second[0]==s.second[0]&&c.second[1]==s.second[1]&&(s.second[2]-1==c.second[2]||c.second[2]-1==s.second[2]))a[3]=1;
    cout<<a[0]<<a[1]<<a[2]<<a[3];
    return 0;
}
