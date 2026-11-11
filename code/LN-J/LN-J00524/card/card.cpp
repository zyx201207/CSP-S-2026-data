#include <bits/stdc++.h>
using namespace std;

const int M = 3e5+10,N = 5e5+10;

int n,m;
int sum[M];
int a[N];
int p[N];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int i = n;i >= 2;i--){
        for(int j = i-1;j >= 1;j--){
            if(a[i] == a[j]){
                p[j]=i;
                break;
            }
        }
    }
    for(int t = 1;t <= n;t++){
        for(int i = t;i <= n;i++){
            if(p[i]==0){
                sum[a[i]]++;
            }else{
                i = p[i]-1;
            }
        }
    }

    for(int i = 1;i <= m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
