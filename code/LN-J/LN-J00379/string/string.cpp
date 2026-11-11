#include<bits/stdc++.h>
using namespace std;
char x[200000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long a;
    char c;
    long long cnt=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=cnt+1;j<=a+cnt;j++){
            x[j]=c;
        }
        cnt+=a;
    }
    long long m=cnt/2;
    for(int i=1;i<=m;i++){
        if(x[i]!=x[cnt-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
