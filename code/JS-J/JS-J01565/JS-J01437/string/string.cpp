#include<bits/stdc++.h>
using namespace std;
int ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        long long c;
        char a;
        cin>>c>>a;
        for(int j=1;j<=c;j++){
            s+=a;
        }
    }
    long long p=s.size();
    for(long long i=0;i<=p/2;i++){
        long long j=p-i;
        if(i==j){
            cout<<ans;
            return 0;
        }
        if(s[i]!=s[j]){
            s[j]=s[i];
            ans++;
            cout<<i<<' '<<j<<'\n';
        }
    }
    cout<<ans;
    return 0;
}
