#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],b[505],x,c[505];
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i = 1; i <= n;i++) cin>>a[i];
    for (int i = 1; i <= n;i++){
        for (int j = i; j <= n; j++){
            if (b[a[j]]==0) {
                b[a[j]]++;
            }else{
                for (int q = 1; q <= m; q++) b[q]=0;
                b[a[j]]++;
            }

        }
        for (int q = 1; q <= m; q++){
            if (b[q]) {
                c[q]++;
                b[q]=0;
            }

        }
    }
    for (int i = 1; i <= m; i++) cout<<c[i]<<' ';
    return 0;
}
