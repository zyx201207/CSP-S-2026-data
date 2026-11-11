#include<stdio.h>
#include<iostream>
const int N=2000010;
using namespace std;
int c,T,n,ne[N],pe[N];long long d,a[N],res,f10[5010],s10[5010],f[N][3];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        scanf("%d%lld",&n,&d);pe[n+1]=n+1;
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        if(n<=3){printf("0\n");continue;}
        for(int i=1;i<=n;i++){
            ne[i]=max(ne[i-1],i);
            while(ne[i]<n&&a[ne[i]+1]-a[i]<=d)++ne[i];
        }for(int i=n;i>0;i--){
            pe[i]=min(pe[i+1],i);
            while(pe[i]>1&&a[i]-a[pe[i]-1]<=d)--pe[i];
        }if(c<=10&&c!=0){res=0;
            for(int i=4;i<=n;i++){
                f10[i]=s10[i]=1,s10[i+1]=0;
                for(int j=i-1,k=i;j>0&&ne[j]!=j;--j){
                    f10[j]=s10[k]-s10[min(i,ne[j])+1];
                    f10[j]=min(f10[j],3ll);
                    s10[j]=s10[j+1]+f10[j];
                    if(f10[j]==2)res++;
                    if(j==pe[k])k=j;
                }
            }cout<<res<<'\n';continue;
        }if(c==11||c==12){
            if(d*2<=a[3]-a[1]){printf("0\n");continue;}
            printf("%lld\n",max(0ll,n-2*d/(a[2]-a[1])+1));continue;
        }f[1][1]=1,f[2][1]=2,f[3][1]=3;res=0;
        for(int i=4;i<=n;i++){
            f[i][1]=f[i][2]=f[i][0]=0;
            if(pe[i]==pe[pe[i]]){f[i][1]=i-pe[i]+1;continue;}
            if(pe[pe[i]]==pe[pe[pe[i]]]){
                f[i][1]=i-pe[i]+1+pe[pe[i]+1]-pe[pe[i]];
                f[i][2]=min(pe[min(pe[i]+2,i)],pe[i])-pe[pe[i]+1];
                continue;
            }f[i][1]=i-pe[i]+1;
            if(pe[pe[i]+1]>pe[pe[i]]){
                f[i][1]+=f[pe[i]][1]-pe[i]+pe[pe[i]+1]-1;
                f[i][0]=f[pe[i]][0]+f[pe[i]][2]*(pe[pe[i]+1]>pe[pe[i]]+1);
                f[i][2]=min(pe[min(pe[i]+2,i)],pe[i])-pe[pe[i]+1];
            }else if(pe[min(pe[i]+2,i)]>pe[pe[i]]){
                //f[i][2]=min(pe[min(pe[i]+2,i)],pe[i])-pe[pe[i]+1];
                f[i][2]+=f[pe[i]][1]-pe[i]+pe[min(pe[i]+2,i)]-1;
            }
        }for(int i=4;i<=n;i++)res+=f[i][2]+f[i][0];//cout<<f[i][0]<<' '<<f[i][2]<<'\n';
        cout<<res<<'\n';
    }
    return 0;
}/*
5 3
-3 0 2 3 4
*/
