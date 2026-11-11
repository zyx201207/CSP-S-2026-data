#include<bits/stdc++.h>
using namespace std;
long long a,b,l=1,r,c,d;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
    cin>>a;
    long long x[a+1];
    char s[a+1];
    for(int i=1;i<=a;i++){
        cin>>x[i]>>s[i];
        c+=x[i];
    }
    r=a;
    while(r>=l){
        if(s[l]!=s[r]) b+=min(x[l],x[r]);
        if(min(x[l],x[r])==x[l]){
            l++;
            x[r]-=x[l-1];
        }
        else{
            r--;
            x[l]-=x[r+1];
        }

    }
    cout<<b;
return 0;
}
