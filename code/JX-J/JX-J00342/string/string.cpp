#include <bits/stdc++.h>

using namespace std;
long long a[100100];
char c[100100];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string s;
    for(long long i=0;i<n;i++){
        char tmp;
        cin>>a[i]>>tmp;
        c[i]=tmp;
    }
    for(long long i=0;i<n;i++){
        while(a[i]--){
            //cout<<c[i]<<endl;
            s+=c[i];
        }
    }
    //cout<<endl<<s<<endl<<s.size()<<endl;
    long long ans=0;
    for(long long i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}