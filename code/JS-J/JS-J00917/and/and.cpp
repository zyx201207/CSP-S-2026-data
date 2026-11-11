#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,m,i,j,andn,maxn,ans=INT_MAX;
int a[N],c[5];
bool b=1;

bool cmp(int a1,int a2){
    return a1<a2;
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
        andn&=a[i];
        maxn=max(maxn,a[i]);
        if(a[i]>=4){
            b=0;
        }
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    if(m==n){
        cout<<andn;
        return 0;
    }
    if(b){
        for(i=n;i<=n;i++){
            c[a[i]]++;
        }
        m-=c[3];
        if(m<=0){
            cout<<3;
        }else if(m-c[2]<=0){
            cout<<2;
        }else if(m-c[1]<=0){
            cout<<1;
        }else{
            cout<<0;
        }
        return 0;
    }
    sort(a+1,a+1+n,cmp);
    if(m==2){
        for(i=1;i<=n;i++){
            if(a[i]<ans){
                cout<<ans;
                return 0;
            }
            for(j=i;j<=n;j++){
                if(ans>a[j]){
                    break;
                }
                if(a[i]&a[j]>=ans){
                    ans=a[i]&a[j];
                }
            }
        }
        cout<<ans;
        return 0;
    }
    for(i=1;i<=m;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}
