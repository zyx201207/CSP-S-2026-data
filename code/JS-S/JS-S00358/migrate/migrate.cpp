#include<bits/stdc++.h>
using namespace std;
long long n,A[305],T,d,C[305][305];
int qread(){
    int x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) {
        if(c=='-') f=-1;
    }
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
/*
int erfeng(long long x){

}
 */

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c = qread();
    T = qread();
    while(T--){
        int ans=0;
        n = qread();d = qread();
        for(int i=1;i<=n;i++)
            A[i]=qread();
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if((A[j]-A[i])<=d) C[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                 if(C[i][j]==0) C[i][j]=1000000000;
            }
        }
        for(int i=1;i<=n;i++){
            int cm=1;
            for(int j=i+1;j<=n;j++){
                for(int k=i+1;k<j;k++){
                    if(C[i][k]+C[k][j]==C[i][j]) cm++;
                    else cm=1;
                    C[i][j]=min(C[i][k]+C[k][j],C[i][j]);
                }
                if(cm==2) ans++;
            }
        }/*
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                 cout<<C[i][j]<<" ";
            }
            cout<<endl;
        }*/
        cout<<ans<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                C[i][j]=1000000000;
            }
        }
        for(int i=1;i<=n;i++)
            A[i]=0;
    }

    return 0;
}
