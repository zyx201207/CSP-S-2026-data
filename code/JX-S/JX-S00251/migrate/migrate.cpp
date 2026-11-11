#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5;
int c,t;
int x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        int ans=0;
        int n,d;
        scanf("%d%d",&n,&d);
        memset(x,0,sizeof(x));
        for(int i=1;i<=n;i++) scanf("%d",&x[i]);
        int start=x[1],END=x[n];
        if(END-start==d+1){
            if(d>2) printf("0\n");
            else cout<<"1"<<endl;
        }
        else{
            for(int i=1;i<=n;i++){
                if(x[i+1]-x[i]>d) continue;
                else{
                    for(int j=i+1;j<=n;j++){
                        if(d+1==x[j]-x[i]) ans++;
                    }
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}