#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
const int N=5000000005;
const int M=500005;
const int S=20005;
const int T=1005;
const int K=105;
//division
int n,a[M],m;
int fun(int n){
    string s;
    while(n>0){
        s=(char)(n%2)+s;
        n/=2;
    }
    int ans=0;
    for(int i=0;i<s.size();i++) ans+=(int)s[i],ans*=10;
    return ans/10;
}
bool cmp(int x,int y){
    return x>y;
}
//division
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //division
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    /*
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
    */
    int ans=a[1];
    cout<<ans;
    //division
    cout.flush();
    cout<<flush;
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
