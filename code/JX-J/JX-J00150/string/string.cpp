#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,sum=0;
    string b,s,t;
    cin>>n;
    while(n--){
        cin>>a>>b;
        for(int i=0;i<a;i++){
            s=s+b;
            t=t+b;
        }
    }
    reverse(s.begin(),s.end());
    for(long long i=0;i<s.size();i++){
        if(s[i]!=t[i])sum++;
    }
    cout<<sum/2;
    return 0;
}
