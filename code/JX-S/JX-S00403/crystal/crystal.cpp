#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n];
    scanf("%d",&a[0]);
    for (int i = 1;i<n;i++){
        int s;
        scanf("%d",&s);
        int k = i;
        for(int j = i-1;j >= 0;j--){
            if(a[j]>s){
                k--;
            }
            else{
                break;
            }
        }
        if(k != i){
            int r = a[k];
            a[k] = s;
            for(int l = k + 1;l <= i;l++){
                int b = a[l];
                a[l] = r;
                r = b;
            }
        }
        else{
            a[i] = s;
        }
    }
    int ans = 0;
    for(int i = 1;i < n;i++){
        int g = 0;
        for(int j = 0;j < i;j++){
            g += (a[i] - a[j]) >= 0 ? (a[i] - a[j]) : (-1) * (a[i] - a[j]);
        }
        if(g > m){
            ans = i;
            break;
        }
    }
    printf("%d",ans);
    return 0;
}
