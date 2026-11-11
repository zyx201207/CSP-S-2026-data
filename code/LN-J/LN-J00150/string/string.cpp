#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a;
    int n;
    cin>>n;
    char x;
    long long len,cnt=0;
    for(int i=1;i<=n;i++){
        cin>>len>>x;
        cnt+=len;
        for(int j=1;j<=len;j++){
            a+=x;
        }
    }
    long long ans1=0,ans2=0;
    for(int i=0;i<cnt/2;i++){
        if(a[i]!=a[cnt-1-i]){
            ans1++;
        }
    }
    cout<<ans1;
    return 0;
}
