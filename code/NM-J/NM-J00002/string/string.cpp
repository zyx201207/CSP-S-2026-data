#include<iostream>
using namespace std;
int main(){
    freopen(" string.in","r",stdin);
    freopen(" string.out","w",stdout);
    int n;
    string a,b,c;
    cin>>a>>b>>c>>n;
    string S,i;
    cin>>S>>i;
    if(a[i]+b[i]+c[i]=S[n]){
        cout<<S[n]-a[i];
    }else{
        cout<<0;
    }
    return 0;
}