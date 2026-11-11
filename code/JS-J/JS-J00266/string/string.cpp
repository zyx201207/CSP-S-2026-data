#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,sum,cur=1;
char wor[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;char c;
        cin>>a>>c;
        sum+=a;
        for(int i=1;i<=a;i++){
            wor[cur]=c;
            cur++;
        }
    }
    for(int i=1;i<=sum/2;i++){
        if(wor[i]!=wor[sum-i+1]) ans++;
    }
    cout<<ans;
    return 0;
}
