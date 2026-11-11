#include<iostream>
using namespace std;
int di,n,a;
string s="";
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    for(int i=0,j=s.size()-1;i<=j,j>=i;i++,j--){
        if(s[i]!=s[j]) di++;
    }
    cout<<di;
    return 0;
}
