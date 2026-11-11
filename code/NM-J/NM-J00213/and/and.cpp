#include<bits/stdc++.h>
using namespace std;
int a[200000];
int h(int x,int y){
    int x1[100];
    int x2=1,y2=1;
    int y1[100];
    int z[100];
    int j=1;
    int c=0;
    while(x>0){
        x1[x2]=x%2;
        x=x/2;
        x2++;
    }
    while(y=0){
        y1[y2]=y%2;
        y=y/2;
        y2++;
    }
    for(int i=max(x2,y2);i>=1;i++){
        if(x1[i]==y1[i])
            z[j]=1;
        else
            z[j]=0;
        j++;
    }
    for(int i=1;i<=max(x2,y2);i++){
        c=c+z[i]*pow(2,i);
    }
    return c;
}
int main(){
  //freopen("and.in","r",stdin);
  //freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxn=0;
    for(int i=1;i<=n;i++){
        int b[100];
        b[1]=a[i];
        for(int j=2;j<=m;j++){
            int c=i+j;
            if(c>n){
                c-=n;
            }
            b[j]=a[c];
        }
        int d=b[1];
        for(int j=2;j<=m;j++){
            d=h(d,b[i]);
        }
        maxn=max(maxn,d);
    }
    cout<<maxn;
    return 0;
}
