#include<iostream>
using namespace std;
int n,m,a[500005];
struct o{
    int x,f=1;
}b[500005];
int ans[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            b[j].x=a[j];
            for(int k=i;k<j;k++){
                if(b[k].x==b[j].x&&b[k].f==1){
                    for(int u=k;u<j;u++){
                        b[u].f=0;
                    }
                    break;
                }
            }
        }
        for(int j=i;j<=n;j++){
            if(b[j].f==1)ans[b[j].x]++;
        }
        for(int j=i;j<=n;j++){
            b[j].f=1;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
