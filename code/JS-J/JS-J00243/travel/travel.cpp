#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int len1=c1.size();
    bool flag=1;
    for(int i=0;i<len1;i++){
        if(c1[i]!=c2[i]) flag=0;
    }
    if(!flag){
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    int len2=s2.size();
    for(int i=0;i<len2-1;i++){
        if(s1[i]!=s2[i]) flag=0;
    }
    if(!flag){
        cout<<"000";
        return 0;
    }
    cout<<"1";
    char x=s1[len2-1],y=s2[len2-1];
    int x1=x-'A';int x2=y-'A';
    if(x1>=3 && x2>=3) cout<<"11";
    else if((x1<=2 && x2>=3) || (x1>=3 && x2<=2)) cout<<"00";
    else{
        if(abs(x1-x2)==1) cout<<"11";
        else cout<<"10";
    }
    return 0;
}
