#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m<=2&&n<=10000){
        int maxn=-1000000000;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxn=max(maxn,a[i]&a[j]);
            }
        }
        cout<<maxn;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[m];
    return 0;
}
