#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
long long a[200005];
char c[200005];
string ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            ans=ans+c[i];
        }
    }
    int k=0;
    while(k<=(ans.size()/2)){
        int t=ans.size()-k;
        if(ans[k]!=ans[t]){
            cnt++;
        }
        k++;
    }
    cout<<cnt;
    return 0;
}
