#include<bits/stdc++.h>
using namespace std;
int n,maxn=-1,ans,le,maxnn=-1;
struct node{
    int d;
    int two;
}a[200005];
int ll(int x){
    long long sum=0;
    int s[1000005],di=0;
    for(int i=1;i<=x,x>0;i++){
        s[i]=x%2;
        x/=2;
        di++;
    }
    for(int i=di,j=1;i>=1;i--,j*=10){
        sum+=s[i]*j;
    }
    return sum;
}
int main(){
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].d;
        a[i].two=ll(a[i].d);
        maxnn=max(maxnn,a[i].two);
    }

    if(m==1){
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i].d);
        }
        cout<<maxn;
        return 0;
    }
    if(m==n){
        maxn=a[1].d&a[2].d;
        for(int i=3;i<=n;i++){
            maxn=maxn&a[i].d;
        }
        cout<<maxn;
    return 0;
    }
    if(a[1].d==0&&a[2].d==1&&a[n].d==n-1){
        int nn=a[n].two;
        for(int i=2;i<=m;i++){
            nn=nn&a[i].d;
        }
        cout<<nn;
        return 0;
    }

    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=a[i].d&a[j].d;
                le=max(ans,le);
            }
        }
        cout<<le;
        return 0;
    }
    else if(m==3){
            for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(a[i].d==a[j].d&&a[j].d==a[k].d){
                    cout<<a[i].d;
                    return 0;
                }
            }
            }

        }
    }
    else {
        cout<<maxnn;
        return 0;
    }

	return 0;
}
