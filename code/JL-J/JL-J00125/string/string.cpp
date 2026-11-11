#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long a;
        cin>>a;
        char b;
        cin>>b;
        for(long long i=1;i<=a;i++){
            s+=b;
        }

    }
    long long cnt=0;
    long long mid=0;
    if(s.length()%2==0){
        mid=s.length()/2-1;
        for(long long i=0;i<s.length();i++){
            if(i>mid){
                long long m=(i-mid)*2-1;
                if(s[i]!=s[i-m]){
                    s[i]=s[i-m];
                    cnt++;
                }
            }
        }
    }

    else if(s.length()%2==1){
        mid=s.length()/2;
        for(long long i=0;i<s.length();i++){
            if(i>mid){
                long long m=i-mid*2;
                if(s[i]!=s[i-m]){
                    s[i]=s[i-m];
                    cnt++;
                }
            }
        }

    }
    cout<<cnt;
    return 0;
}

