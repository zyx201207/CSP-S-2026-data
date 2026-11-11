#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1,s1,c2,s2;
    int n=0,m=0,a=0,b=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1=c2){
        n=1;
    }else{
        cout<<n<<m<<a<<b;
        return 0;
    }
    if(s1+1==s2||s1-1==s2){
        m=1;
    }
    cout<<n<<m<<a<<b;
    return 0;
}

