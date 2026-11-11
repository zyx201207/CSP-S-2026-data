#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50,M=3e5+50;
int n,m;
int a[N];
int s[M];
bool v[M];
int c[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(v,0,sizeof(v));
        memset(c,0,sizeof(c));
        int cnt=0;
        for(int j=i;j<=n;j++){
            cnt++;
            if(v[a[j]]){
                for(int k=cnt-1;k>=1;k--){
                    if(c[k]==a[j]){
                        cnt--;
                        c[k]=0;
                        v[a[j]]=0;
                        break;
                    }
                    cnt--;
                    v[c[k]]=0;
                    c[k]=0;
                }
            }
            c[cnt]=a[j];
            v[a[j]]=1;
        }
        for(int j=1;j<=m;j++){
            if(v[j]){
                s[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}
