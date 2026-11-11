#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string s;
    for(long long i=1;i<=n;i++){
        long long z;
        char a;
        cin>>z>>a;
        for(long long j=1;j<=z;j++){
            s+=a;
        }
    }
    long long x,y,mid=s.size();
    if(mid%2==0){
        x=mid/2-1;
        y=mid/2;
        mid/=2;
    }else{
        x=mid/2;
        y=mid/2;
        mid/=2;
        mid+=1;
    }
    long long ans=0;
    for(long long i=1;i<=mid;i++){
        if(s[x]!=s[y]){
            ans++;
        }
        x--;
        y++;
    }
    cout<<ans;
    return 0;
}
