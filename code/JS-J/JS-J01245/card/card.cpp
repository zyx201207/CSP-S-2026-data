#include<bits/stdc++.h>
using namespace std;
int s[500005],cnt=0,a[500005],p[500005];
int check(int l){
    for(int i=1;i<=cnt;i++){
        if(s[i]==l){
            return i;
        }
    }
    return 0;
}
int main(){
    freopen("card.in","read",stdin);
    freopen("card.out","write",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cnt=0;
        for(int j=i;j<=n;j++){
            int o=check(a[j]);
            if(o==0){
                s[++cnt]=a[j];
            }
            else{
                cnt=o;
            }
        }
        for(int k=1;k<=cnt;k++){
            p[s[k]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<p[i]<<" ";
    }
    return 0;
}
