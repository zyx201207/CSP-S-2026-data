#include <bits/stdc++.h>
using namespace std;
long long a[200001],b[200001];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(m==1){
        cout<<a[1];
        return 0;
    }else if(m==n){
        int l=a[1];
        for(int i=2;i<=n;i++){
            l&=a[i];
        }
        cout<<l;
        return 0;
    }
    for(int i=1;i<=n;i++){
        int x=0;
        int s=a[i];
        for(int j=i+1;j<=n;j++){
            for(int x=1;x<m;x++){
                if(i+m>n){
                    break;
                }else{
                    s&=a[j+m];
                    b[x]=s;
                    x++;
                }
            }
        }
    }
    sort(b+1,b+n+1,cmp);
    cout<<b[1];
    return 0;
}
