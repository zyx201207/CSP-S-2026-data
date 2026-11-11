#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n=0;
    long long xiabiao=0;
    cin>>n;
    string s;
    long long a;
    char c,beifen_c;
    bool panduan=1;
    cin>>a>>c;
    beifen_c=c;
    xiabiao+=a;
    for(long long i=0;i<a;i++){
        s[i]=c;
    }
    for(long long i=1;i<n;i++){
        int a;
        char c;
        cin>>a>>c;
        if(beifen_c!=c){
            panduan=0;
        }
        for(long long j=xiabiao;j<xiabiao+a;j++){
            s[j]=c;
        }xiabiao+=a;
    }
    if(panduan==1){
        cout<<0<<endl;
        return 0;
    }
    long long l=0,r=xiabiao,ans=0;
    while(l<=r){
        if(s[l]!=s[r]){
            ans++;
        }l++;
        r--;
    }cout<<ans;
    return 0;
}

