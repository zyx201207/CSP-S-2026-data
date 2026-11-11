#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000010];
int L[2000010],R[2000010];
int ll[2000010][23],ck[2000010][23],ss[2000010][23];
int ask(int l,int r,int x){
    int cnt=0;
    for(int i=l;i<=r;i++){
        if(R[i]==x)cnt++;
    }
    return cnt;
}
int quan[2000010][23];
int cun[2000010],cuncun[2000010];

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int id,T;
    cin>>id>>T;
    while(T--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            // if(i!=1){
            //     cerr<<a[i]-a[i-1]<<" ";
            // }
        }
        // cerr<<"\n";
        for(int i=1;i<=n;i++){
            R[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
            L[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
            ll[i][0]=L[i];
            ck[i][0]=0;
            quan[i][0]=ask(L[i],i-1,i);
        }
        for(int i=1;i<=n;i++){
            if(R[L[i]]==i&&L[i]!=i){
                ck[i][0]=1;
            }
        }
        for(int i=1;i<=21;i++){
            for(int j=1;j<=n;j++){
                ll[j][i]=ll[ll[j][i-1]][i-1];
                ck[j][i]=(ck[j][i-1]&ck[ll[j][i-1]][i-1]);
                quan[j][i]=quan[j][i-1]+quan[ll[j][i-1]][i-1];
            }
        }
        for(int i=1;i<=n;i++){
            cuncun[i]=0;
            int now=i;
            for(int j=21;j>=0;j--){
                if(ck[now][j]){
                    cuncun[i]+=quan[now][j];
                    now=ll[now][i];
                }
            }
            cuncun[i]+=quan[now][0];
        }
        for(int i=1;i<=n;i++){
            cun[i]=0;
            if(R[L[L[i]]]==L[i]+1&&R[L[i]+1]==i){
                cun[i]=ask(L[L[i]],L[i]-1,L[i]+1);
                cun[i]+=cuncun[L[L[i]]];
            }
            ss[i][0]=cun[i];
        }
        for(int i=1;i<=21;i++){
            for(int j=1;j<=n;j++){
                ss[j][i]=ss[j][i-1]+ss[ll[j][i-1]][i-1];
            }
        }
        int sum=0;
        for(int i=1;i<=n;i++){
            int now=L[i];
            for(int j=21;j>=0;j--){
                if(ck[now][j]){
                    sum+=ss[now][j];
                    now=ll[now][j];
                }
            }
            sum+=cun[now];
        }
        for(int i=1;i<=n;i++){
            sum+=ask(L[L[i]],L[i]-1,L[i]+1);
            if(R[L[L[i]]]==L[i]+1){
                sum+=cuncun[L[L[i]]];
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}
/*
0 1
10 3
0 3 6 8 10 11 12 13 15 18

*/