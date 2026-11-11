#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
    cin>>n;
    string s;
    long m=0;
    long p=0;
    for(int i=1;i<=n;i++){
        long long a;
        cin>>a;
        char b;
        cin>>b;
        for(int j=1;j<=a;j++){
            s[m]=b;
            m++;
        }
        p+=a;
    }
    long long ans=0;
    if(p%2==0){
        for(int i=0;i<=p/2-1;i++){
            if(s[i]!=s[p-i-1])ans++;
        }
    }
    else{
        for(int i=0;i<=(p-1)/2-1;i++){
            if(s[i]!=s[p-i-1])ans++;
        }
    }
    cout<<ans;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    return 0;
}
