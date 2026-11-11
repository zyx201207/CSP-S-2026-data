#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
char c;
string cc;
long long s,m;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>a[i]>>c;
        for(int j=1;j<=a[i];j++) cc+=c;
    }
    m=(cc.size())/2;
    for(int i=0;i<m;i++) if(cc[i]!=cc[n-i+1]) s++;
    cout <<s;
    return 0;
}
