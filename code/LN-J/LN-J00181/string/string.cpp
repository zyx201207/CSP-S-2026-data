#include<bits/stdc++.h>
using namespace std;
long long n,a,ans=0;
string s,c;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a>>c;
        for(long long j=1;j<=a;j++){
            s+=c;
        }
    }
    for(long long i=1;i<=s.size()/2;i++){
        if(s[i-1]!=s[s.size()-i]){
            ans++;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
