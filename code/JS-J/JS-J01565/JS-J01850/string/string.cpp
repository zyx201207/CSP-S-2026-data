#include<bits/stdc++.h>
using namespace std;
int s[200020];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char d;
    int k=1;
    string a;
    int n;
    long long cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        char c;
        cin>>c;
        if(d!=c&&i!=1)
            k=0;
        d=c;
        int m=s[i];
        while(m>0)
            {a+=c;
            m--;}
    }
    if(k){
        cout<<0;
        return 0;
    }
    string b=a;
    reverse(a.begin(),a.end());
    if(b==a)
    {
        cout<<0;
        return 0;
    }
    int x=b.size();
    for(int i=x-1;i>=0;i--){
        if(b[i]!=b[x-1-i])
        {
            cnt++;
            b[i]=b[x-1-i];
        }
    }
    cout<<cnt;
    return 0;}
