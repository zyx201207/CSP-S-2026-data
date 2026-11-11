#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
bool pd(char a,char b){
    int cnt=0;
    if('A'<=a&&'C'>=a)cnt+=1;
    if('A'<=b&&'C'>=b)cnt+=1;
    return cnt%2;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)a=1;
    else {
        cout<<"0000"<<endl;
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        b=1;
    }
    else{
        cout<<"1000";
        return 0;
    }
    if(pd(s1[2],s2[2])==0){
        c=1;
    }
    else{
        cout<<"1100";
        return 0;
    }
    if(abs(s1[2]-s2[2])==1){
        cout<<"1111";
        return 0;
    }
    else {
        cout<<"1110";
        return 0;
    }
    return 0;
}
