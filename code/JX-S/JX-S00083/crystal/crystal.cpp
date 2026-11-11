#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+7;
int n,sum = 0,dis = 0,p = 1,num[maxn],maxs = -1;
long long m,a[maxn],b[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    b[1] = 0;
    for(int i = 1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i = 2;i<=n;i++){
        b[i] = b[i-1]+(a[i] - a[i-1])*(i-1);
        if(b[i]>m){
            for(int j = p;j<=i;j++){
                if(b[i]-=(a[i] - a[j])<=m){
                    p = j;
                    num[j] = i - j + 1;
                    if(maxs < num[j])maxs = num[j];
                }
            }
        }
    }
    cout<<maxs;
    return 0;
}
