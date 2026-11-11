#include<bits/stdc++.h>;
using namespace std;
#define int long long
int n,a,sum,num;
char c;
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    s=' ';
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;
        j<=a;j++){
            s=s+c;
        }
        sum+=a;
    }
    int k=sum-1;
    for(int i=1;i<=sum/2;i++){
        if(s[i]!=s[i+k]){
            num++;
        }
        k-=2;
    }
    cout<<num;
}
