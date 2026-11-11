#include<bits/stdc++.h>
using namespace std;
string stra,strb;
long long n,a[200009],k,cnt;
char c[100000009];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++) stra+=c[i];
    }
    k=stra.size()-1;
    for(int i=0;i<=k;i++){
        if(stra[i]!=stra[k]){
            cnt++;
            stra[i]=stra[k];
        }
        k--;
    }
    cout<<cnt;
    return 0;
}

