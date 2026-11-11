#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    string x="";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            x+=c[i];
        }
    }
    string y=x;
    reverse(y.begin(),y.end());
    if(y==x){
        cout<<0;
        return 0;
    }
    ll cnt=0;
    int i=0;int j=x.size()-1;
    while(i<=j){
        if(x[i]!=x[j])cnt++;
        i++;
        j--;
    }
    cout<<cnt;
    return 0;
}
