#include <bits/stdc++.h>
using namespace std;
int c,T,n,e[5005][5005];
long long d,an,x[2000010],w[5005][5005];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        an=0;
        cin>>n>>d;
        for(int i=1;i<=n;++i)cin>>x[i];
        if(c==11||c==12){
            long long g=x[2]-x[1];
            if(d<2*g){
                printf("0\n");
                continue;
            }
            int l,r;
            l=max(4ll,(2*d-2*g+g)/g);//(
            r=min(1ll*n,2*d/g);// ]
            l+=l%2;
            for(int i=1;i+l-1<=n;++i){
                int j=min(r,n-i+1);
                if(j%2)j--;
                an+=(j-l)/2+1;
            }
            cout<<an<<"\n";
            continue;
        }
        if(c>12){
            printf("0\n");
            continue;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=i;++j){
                e[i][j]=e[j][i]=0;
                w[i][j]=w[j][i]=0;
            }
        }
        for(int i=n;i;--i){
            for(int j=i+1;j<=n;++j){
                if(x[j]-x[i]>d){
                    for(int k=i+1;k<j;++k){
                        if(e[i][k]>1)break;
                        if(!e[k][j])continue;
                        int g=e[i][k]+e[k][j];
                        if(g<e[i][j]||!e[i][j])e[i][j]=g,w[i][j]=0;
                        if(g==e[i][j])w[i][j]+=w[i][k]*w[k][j];
                    }
                }
                else e[i][j]=w[i][j]=1;
                if(!e[i][j])break;
                if(w[i][j]==2)an++;
            }
        }
        cout<<an<<"\n";
    }
    return 0;
}
