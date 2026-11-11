#include <bits/stdc++.h>
using namespace std;
string l,x,y;
char s;
long long n,a,b=0;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio();
cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>s;
        for(int i=1;i<=a;i++){
            l+=s;
        }
    }
    if(l.size()%2==1){
        for(int i=0;i<=l.size()/2;i++){
            x+=l[i];
        }
        for(int i=l.size();i>=l.size()-l.size()/2;i--){
            y+=l[i];
        }
    }
    else{
        for(int i=0;i<=l.size()/2;i++){
            x+=l[i];
        }
        for(int i=l.size();i>=l.size()-l.size()/2;i--){
            y+=l[i];
        }
    }
        for(int i=0;i<=l.size()/2-1;i++){
            if(x[i]!=y[i]) b++;
        }
    cout<<b;
    return 0;
}
