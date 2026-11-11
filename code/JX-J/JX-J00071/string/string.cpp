#include<bits/stdc++.h>
using namespace std;
long long n,totle=0,j=1;
long long a[200005];
string c;
string s[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c;
        long long k=j;
        for(j;j<=k+a[i];j++){
            s[j]=c;
        }
    }
    if(n%2==0){
        for(int i=1;i<=n/2;i++){
            if(s[i]!=s[n+1-i]){
                totle++;
            }
        }
    } else {
        for(int i=1;i<=(n-1)/2;i++){
            if(s[i]!=s[n+1-i]){
                totle++;
            }
        }
    }
    cout<<totle<<"\n";
    return 0;
}
