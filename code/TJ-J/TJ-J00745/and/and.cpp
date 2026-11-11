#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int n,m,a[200005],x;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%d",&a[1]);
    x=a[1];
    for(int i=2;i<=n;i++){
        scanf("%d",&a[i]);
        x&=a[i];
    }
    if(m==n){
        printf("%d",x);
    }
    else if(m==1){
        x=0;
        for(int i=1;i<=n;i++){
            x=max(x,a[i]);
        }
        cout<<x;
    }
    else if(m==2){
        x=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    x=max(x,a[i]&a[j]);
                }
            }
        }
        cout<<x;
    }
    else if(m==n-1){
        x=0;
        int y=0;
        for(int i=1;i<=n;i++){
            y=0;
            for(int j=1;j<=n;j++){
                if(j!=i){
                    if(y==0){
                        y=a[j];
                    }
                    else{
                        y&=a[j];
                    }
                }
            }
            x=max(x,y);
        }
        cout<<x;
    }
    else{
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=m;i++){
            x=x&a[i];
        }
        cout<<x;
    }
    return 0;
}
