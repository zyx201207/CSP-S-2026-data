#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string,out","w",stdout);
    long long n,cnt=0,cntt=0;
    string s={0},ss={0};
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        char c;
        cin>>x>>c;
        for(int j=0;j<x;j++){
            s+=c;
        }
    }
    long long h=s.size();
    if(s.size()==1){
        cout<<0;
    }else{
        if(h%2==0){
            for(int i=0;i<h/2+1;i++){
                char c=s[i];
                ss+=c;
            }
    reverse(ss.begin(),ss.end());
    for(int i=h/2+1;i<h;i++){
        if(s[i]==ss[i-h/2]){
            continue;
        }else{
            cnt++;
            }
        }
        cout<<cnt;
        }else{
            s[h/2]+=0;
            for(int i=0;i<h/2+1;i++){
                char c=s[i];
                ss+=c;
            }
    reverse(ss.begin(),ss.end());
    for(int i=h/2+1;i<h;i++){
        if(s[i]==ss[i-h/2]){
            continue;
        }else{
            cntt++;
            }
        }
        cout<<cntt;
        }
    }
    return 0;
}
