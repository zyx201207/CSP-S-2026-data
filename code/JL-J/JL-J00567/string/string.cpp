#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,a[200000+10],sum,t,cnt;
char c[200000+10];
string b;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            b=b+c[i];
        }
    }
    for(int i=0;i<=b.size()/2;i++){
        if(b[i]!=b[b.size()-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
