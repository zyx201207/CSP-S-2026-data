#include <bits/stdc++.h>
using namespace std;
int cur[500010],n,m;

void op(int a,int b,int id){
    cur[id]=b-a;
}
void B(int u){
    int k=0;
    for(int i=1;i<=m;i++){
        k=i*u+k;
        if(k>m){
            cout<<i;
            break;
        }
    }
    return ;
}
int main()
{
    bool o=1;
    cin>>n>>m;
    int a[500010];
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int t=a[2]-a[1];
    for(int i=2;i<n;i++){
        int t1=a[i+1]-a[i];
        if(t!=t1){
            o=0;
            break;
        }
    }
    if(o){
        B(t);
        return 0;
    }
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if(a[i]>a[j]){
                int k=a[i];
                a[i]=a[j];
                a[j]=k;
            }
        }
    }
    cur[1]=a[2]-a[1];
    for(int i=2;i<n;i++){
        op(a[i],a[i+1],i);
        cout<<cur[i]<<endl;
    }
    for (int i=1;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if(cur[i]>cur[j]){
                int k=cur[i];
                cur[i]=cur[j];
                cur[j]=k;
            }
        }
    }
    cout<<endl;
    for (int i=1;i<n;i++){
        if(m-cur[i]<0){
            cout<<endl;
            cout<<i;
            return 0;
        }
        cout<<m<<endl;
        m=m-cur[i];
    }
}
