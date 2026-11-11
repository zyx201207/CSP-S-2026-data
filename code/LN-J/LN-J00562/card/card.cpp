#include <bits/stdc++.h>
using namespace std;
const int maxn=100;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int a[maxn]={0};
    int b[maxn]={0};
    int ans[maxn]={0};
    long long n,m;
    cin >> n;
    cin >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++){
        long long nowl=1;
        for (int j=i;j<=n;j++){
            long long k=a[j];
            bool y=false;
            long long c=j;
            while(c<=n){
                if (b[c]==k){
                    y=1;
                    nowl=c;
                    break;
                }
                c++;
            }
            int x=nowl;
            while (x<=n){
                b[x]=0;
                x++;
            }
            b[nowl]=k;
            nowl++;
        }
        for (int j=1;j<=n;j++){
            int w=b[j];
            ans[w]++;
            b[j]=0;
        }
    }
    for (int i=1;i<=m;i++){
        cout <<ans[i]<<" ";
    }
    return 0;
}
