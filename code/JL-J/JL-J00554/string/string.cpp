#include<bits/stdc++.h>
using namespace std;
const int q=2e5+10;
unsigned long long n,a[27],sum=0,a1;
string s,s1,s2;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    cin>>n;
    for(unsigned long long i=0;i<n;i++){
        cin>>a1>>c;
        for(unsigned long long j=0;j<a1;j++)s+=c;
    }
    for(unsigned long long i=0;i<s.length()/2;i++){
        s1+=s[i];
    }
    for(unsigned long long i=s.length()-1;i>s.length()/2;i--){
        s2+=s[i];
    }
    for(unsigned long long i=0;i<s.length()/2;i++){
        if(s1[i]!=s2[i]){
            sum++;
        }
        cout<<i<<' '<<s1[i]<<' '<<s2[i]<<endl;
    }
    cout<<sum;
    return 0;
}

