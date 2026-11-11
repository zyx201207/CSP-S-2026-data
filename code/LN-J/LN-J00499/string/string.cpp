#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,len=1,x[200005];
    char c[200005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>c[i];
        len+=x[i];
    }
    len--;
    long long ans=len/2;
    for(int i=0;i<n/2;i++){
        if(c[i]==c[n-i-1]){
            ans-=min(x[i],x[n-i-1]);
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
