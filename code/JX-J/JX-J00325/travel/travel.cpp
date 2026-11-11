#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000"<<endl;
        return 0;
    }else if(s1[0]!=s2[0] || s1[1]!=s2[1]){
        cout<<"1000"<<endl;
        return 0;
    }else if(s1.find("C")!=EOF && s2.find("D")!=EOF || s1.find("D")!=EOF && s2.find("C")!=EOF){
        cout<<"1100"<<endl;
        return 0;
    }else if(s1.find("A")!=EOF && s2.find("B")!=EOF || s1.find("B")!=EOF && s2.find("A")!=EOF || s1.find("B")!=EOF && s2.find("C")!=EOF || s1.find("C")!=EOF && s2.find("B")!=EOF || s1.find("D")!=EOF && s2.find("F")!=EOF || s1.find("F")!=EOF && s2.find("D")!=EOF){
        cout<<"1111"<<endl;
        return 0;
    }else{
        cout<<"1110"<<endl;
        return 0;
    }
}
