#include <bits/stdc++.h>
using namespace std;
int num=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,x;
    cin >> n;
    string sum[1000000001],cnt[n];
    string w;
    for(int i=1;i<=n;i++){
        cin >> x;
        cin >> n[i-1];
        for(int j=1;j<=x;j++){
            sum[i]+=n[i-1];
        }
    }
    for(int i=1;i<=n;i++){
        w+=sum[i-1];
    }
    int q=w.size();
    for(int i=0;i<q/2;i++){
        if(w[i]!=w[q+1-i]){
            num++;
        }
    }
    cout << 1;
    return 0;
}

