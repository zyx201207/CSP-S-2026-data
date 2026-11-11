#include<bits/stdc++.h>
using namespace std;
long long tongji(string s){
    long long l=0,r=s.size()-1;
    long long cnt=0;
    while(l<r){
        if(s[l]==s[r]){
            l++;
            r--;
        }else{
            cnt++;
            l++;
            r--;
        }
    }
    return cnt;
}
int n;
string s;
long long a[2000005];
char c[2000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(a[i]>=1e7){
            cout<<n/2*a[i];
            return 0;
        }
        for(long long j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    cout<<tongji(s);
    return 0;
}
