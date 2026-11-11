#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
bool b[200010];
int main(){
    memset(b,1,sizeof(b));
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    a[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int f[m];
    memset(f,0,sizeof(f));
    for(int i=0;i<m;i++){
        if(i==0){
            int ans=0;
            for(int j=1;j<=n;j++){
                if(a[j]>=a[ans]){
                    ans=j;
                }
            }
            f[i]=a[ans];
            b[ans]=0;
            continue;
        }
        int ans=0;
        for(int j=1;j<=n;j++){
            if(b[j]!=0 &&(a[j]&f[i-1])>=(a[ans]&f[i-1])){
                ans=j;
            }
        }
        f[i]=a[ans]&f[i-1];
        b[ans]=0;
    }
    cout<<f[m-1]<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
