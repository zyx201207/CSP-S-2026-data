#include<bits/stdc++.h>
using namespace std;
int main () {
    int r,w;
    freopen("string","r",stdin);
    freopen("string","w",stdout);
    long long n,a,h=0,t;
    char c,s[1000000];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        h+=a;
        for(int j=1;j<=a;j++){
            s[j]=c;
        }
    }
    if(h%2==0){
    t=h/2;
        for(int i=1;i<=h/2;i++){
            for(int j=h;j>=h/2;j--){
                if(s[i]==s[j]){
                    t--;
                }
            }
        }
        cout<<t;
    }
    else {
    t=h/2+1;
         for(int i=1;i<=h/2-1;i++){
            for(int j=h;j>=h/2+1;j--){
                if(s[i]==s[j]){
                    t--;
                }
            }
        }
        cout<<t+1;
    }
return 0;
}

