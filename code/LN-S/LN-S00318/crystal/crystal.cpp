#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w".stdout);
    cin>>tie(0);
    string s;
    cin>>s;
    long long n,m,num=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    n+=num;
        for(int i=1;i<=m;i++){
        m+=num;
        s++;
        }
        num++;
    }
    cout<<num;
    return 0;
}
