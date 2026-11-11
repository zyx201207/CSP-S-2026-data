#include <bits/stdc++.h>
using namespace std;
bool d[26];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,maxn=0;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    string t="";
    for(int i=1;i<=n;i++){
        long long c;
        char b;
        cin>>c>>b;
        d[b-'a']=1;
        for(int j=1;j<=c;j++){
            t+=b;
        }
    }
    string a="";
    for(int i=t.size()-1;i>=0;i--){
        a+=t[i];
    }
    if(a==t){
        cout<<0;
        return 0;
    }
    long long sum=0;
    for(int i=0;i<26;i++){
            sum=0;
        if(d[i]==1){
            for(int j=0;j<t.size();j++){
                  if(a[j]=='a'+i&&a[j]!=t[j]){
                    sum++;
                  }
            }
        }
        maxn=max(maxn,sum);
    }
    cout<<maxn;
}
