#include<bits/stdc++.h>
using namespace std;
long long n,t=0,x,z=0;
char y;
vector<char> s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;

    for(long long i=1;i<=n;i++){
        cin>>x>>y;
        z+=x;
        while(x--){
            s.push_back(y);
        }

    }
    for(long long i=0,j=z-1;i<z/2,j>=z-z/2;i++,j--){
        if(s[i]!=s[j]){
            t++;
        }
    }
    cout<<t;
    return 0;
}
