#include <bits/stdc++.h>
using namespace std;

int a[500005];
bool v[300005];
int t[500005];
int ct[300005];
bool cv[300005];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int cnt=0;
    for(int i=1; i<=m; i++){
        int j=1;
        for(int k=i; k<=n; k++){
            if(v[a[i]]){
                int u;
                for(int l=1; l<j; l++){
                    if(t[l]==a[i]) u=l;
                }
                j=u;
                for(int l=1; l<=m; l++) v[l]=0;
                for(int l=1; l<j; l++) v[t[l]]=1;
            }
            t[j]=a[i];
            j++;
        }
        for(int k=1; k<j; k++){
            cv[t[k]]=1;
        }
        for(int k=1; k<=m; k++){
            if(cv[k]) ct[k]++;
            cv[k]=0;
        }
    }
    for(int i=1; i<=m; i++){
        cout << ct[i] << ' ';
    }
    return 0;
}
