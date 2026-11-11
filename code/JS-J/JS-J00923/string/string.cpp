#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"0"<<endl;
        return 0;
    }
    string s="";
    int a1,b1;
    char a2,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a2==b2)
    {
        cout<<"0"<<endl;
        return 0;
    }
    cout<<min(a1,b1)<<endl;
    return 0;
}