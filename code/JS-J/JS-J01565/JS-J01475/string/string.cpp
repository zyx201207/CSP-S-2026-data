#include<bits/stdc++.h>
using namespace std;
long long n,j[1000010];
int c1=0;
string  s,c,s1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>j[i]>>s[i];

    }
    for(int i=2;i<=n;i++){
        if(s[i]==s[i-1]) c1++;
        if(c1==n-1){
            cout<<"0";
            return 0;
        }
        else cout<<j[i]*3;
    }



    return 0;
}
