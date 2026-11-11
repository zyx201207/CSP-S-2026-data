#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],maxn=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>maxn) maxn=a[i];
    }
    if(m==1){
        cout<<maxn<<endl;
        return 0;
    }
    maxn=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            int sum=a[i];
            int l=j;
            for(int k=2;k<=m;k++){
                sum&=a[l++];
                if(l==i) l++;
            }
            if(sum>maxn) maxn=sum;
        }
    }
    cout<<maxn<<endl;
    return 0;
}
