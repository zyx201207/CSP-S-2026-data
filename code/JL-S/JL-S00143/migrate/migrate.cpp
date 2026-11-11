#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e6;
int case_num,T;
int n,prv[N],nxt[N]; ll d,a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&case_num,&T);
    while(T--){
        ll ans=0;
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%lld",a+i);
        if(n==1){
            puts("0");
            continue;
        }
        for(int i=1,j=1;i<=n;i++){
            j=max(j,i);
            while(j<n&&a[j+1]-a[i]<=d)
                ++j;
            nxt[i]=j;
        }
        for(int i=n,j=n;i>=1;i--){
            j=min(j,i);
            while(j>1&&a[i]-a[j-1]<=d)
                --j;
            prv[i]=j;
        }
        if(case_num==11||case_num==12){
            ll h=d/(a[2]-a[1]);
            if(h>1)
                ans=max(0ll,n-h-h+1);
        }else if(case_num==13||case_num==14){
            for(int l=1,r=nxt[1]+1;r<=n;l++){
                r=max(r,nxt[l]+1);
                while(r<=n&&nxt[l]-prv[r]>1) ++r;
                while(r<=n&&nxt[l]-prv[r]==1)
                    ++ans,++r; 
            }
        }else{
            //puts("here");
         
            for(int l=1,r=nxt[1]+1;r<=n;l++){
                r=max(r,nxt[l]+1);
                while(r<=n&&nxt[l]-prv[r]>1) ++r;
                while(r<=n&&nxt[l]-prv[r]==1){
					int lw=1,rw=1;
					for(int lim=l,rim=l;lim>=1;lim--)
                        if(nxt[lim]==rim)
                            lw+=(lim!=l),rim=lim;
                    for(int lim=r,rim=r;rim<=n;rim++)
                        if(prv[rim]==lim)
                            rw+=(rim!=r),lim=rim;
                    //printf("%d %d %d %d\n",l,r,lw,rw);
                    ans+=lw*rw;
                    ++r; 
                    
                 }
            }

        }
        printf("%lld\n",ans);
    }
    return 0;
}
//g++ -Wall -std=c++14 -fsanitize=address migrate.cpp -o migrate;./migrate
//diff -s migrate.ans migrate_my.out
/*
0 2
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
 * */
