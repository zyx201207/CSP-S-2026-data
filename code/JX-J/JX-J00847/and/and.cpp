#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[114514],x=0,b[114514],t,num=0,y,z;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    y=m;
    while(m--){
       for(int i=0;i<n;i++){
            if(a[i]>=x){
                x=a[i];
                t=i;
            }
            if(i==n-1){
                a[t]=0;
            }
        }
        b[num]=x;
        x=0;
        num++;
    }
    z=b[0];
    for(int i=1;i<y;i++){
        z=b[i]&z;
    }
    cout<<z;
    return 0;
}
