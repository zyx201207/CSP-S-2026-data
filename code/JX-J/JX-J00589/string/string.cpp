#include<bits/stdc++.h>
using namespace std;
int n,b,c,sum;
string s;
char a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b>>a;
        for(int j=0;j<b;j++){
            s+=a;
        }
    }
    while(n-c>=c){
        if(s[c]!=s[n-c]){
            sum++;
        }
        c++;
    }
    cout<<sum;
}
