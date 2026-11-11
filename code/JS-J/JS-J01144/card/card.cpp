#include<bits/stdc++.h>
using namespace std;
int n,m,t,k,f;
bool flag=1;
int a[500010],b[300010],c[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<n<<endl;
        return 0;
    }
    for(int i=1;i<n;i++){
        if(a[i]>a[i+1]) flag=0;
    }
    if(flag==1){
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i+1]){
                cout<<i<<" ";
            }
        }
    }
    t=1;
    while(t<=n){
        memset(b,0,sizeof(b));
        k=0;
        for(int i=t;i<=n;i++){
            f=0;
            for(int j=1;j<=k;j++){
                if(a[i]==b[j]){
                    f=j;
                    break;
                }
            }
            if(f==0) b[++k]=a[i];
            else{
                k=f-1;
                for(int j=f+1;j<=n;j++) b[j]=0;
                b[++k]=a[i];
            }
        }
        t++;
        for(int i=1;i<=k;i++){
            c[b[i]]++;
        }
        //for(int i=1;i<=k;i++) cout<<b[i]<<" ";
        //cout<<endl;
    }
    for(int i=1;i<=m;i++) cout<<c[i]<<" ";
    return 0;
}
