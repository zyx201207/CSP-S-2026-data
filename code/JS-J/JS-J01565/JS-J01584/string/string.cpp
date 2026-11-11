#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+5;
int n,ans;
int a[N];
char c[N];
vector<int>len;
vector<char>hd,lt;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1,j=n;i<j;){
        if(a[i]>a[j]){
            len.push_back(a[j]);
            hd.push_back(c[i]);
            lt.push_back(c[j]);
            a[i]-=a[j];
            a[j]=0;
            j--;
        }else if(a[i]<a[j]){
            len.push_back(a[i]);
            hd.push_back(c[i]);
            lt.push_back(c[j]);
            a[j]-=a[i];
            a[i]=0;
            i++;
        }else if(a[i]==a[j]){
            len.push_back(a[i]);
            hd.push_back(c[i]);
            lt.push_back(c[j]);
            a[j]=0;
            a[i]=0;
            i++,j--;
        }
    }
    for(int i=0;i<len.size();i++){
        if(hd[i]!=lt[i]){
            ans+=len[i];
        }
    }
    cout<<ans;
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}