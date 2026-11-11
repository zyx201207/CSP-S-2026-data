#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000005],t[1000005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j && a[i]==a[j])
                t[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        int cnt=0;
        while(t[i]--){
            cnt++;
        }
        cout<<cnt<<" ";
    }
    return 0;
}

