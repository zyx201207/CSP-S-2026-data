#include<bits/stdc++.h>
using namespace std;
long long a[10005],b[10005],n,m,qq=0,x,y,x2,y2;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            x=a[i]&a[j];
            if(x>qq){
                qq=x;x2=i;y2=j;
            }
        }
    }
    b[x2]=1;
    b[y2]=1;
    for(int p=2;p<m;p++){
        y=qq;
        for(int q=0;q<n;q++){
            if(b[q]==0){
                qq=qq&a[q];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                x=y&a[j];
                if(x>qq&&b[j]==0){
                    qq=x;x2=j;
                }
            }
        }
        b[x2]=1;
    }
    cout<<qq;
    return 0;
}
