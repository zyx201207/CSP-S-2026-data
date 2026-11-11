#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,ans=0;
    cin>>n;
    string s;
    for(long long i=1;i<=n;i++){
        long long a;
        cin>>a;
        char c;
        cin>>c;
        for(long long k=1;k<=a;k++){
            s+=c;
        }
        ans+=a;
    }
    long long sum=0;
    if(ans%2==0){
        for(long long i=0;i<ans/2;i++){
            if(s[i]!=s[ans-1-i]){
                sum++;
            }
        }
    }
    else{
        for(long long i=0;i<(ans+1)/2-1;i++){
            if(s[i]!=s[ans-1-i]){
                sum++;
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
