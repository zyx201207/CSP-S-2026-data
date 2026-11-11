#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int N;
    cin>>N;
    long long n=0;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        char c;
        cin>>c;
        for(long long j=n;n<j+x;n++){
            if(n>=1000005){
                cout<<0;
                return 0;
            }
            s[n]=c;
        }
    }
    int ans=0;
    for(int i=0;i<=n>>1;i++){
        if(s[i]!=s[n-i-1])ans++;
    }
    cout<<ans;
    return 0;
}
