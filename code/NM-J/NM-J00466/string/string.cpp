#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long a[N];
unsigned long long cnt;
string s="";
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=a[i];++j){
            s+=c[i];
        }
    }
    for(int i=0;2*i+1<s.size();++i){
        int j=s.size()-i-1;
        if(a[i]!=a[j]){++cnt;}
    }
    cout<<cnt;
    return 0;
}
