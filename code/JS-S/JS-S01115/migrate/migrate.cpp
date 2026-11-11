#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans,cnt1,cnt2;
long long x[2000005];
int qu[2000005],l[2000005],r[2000005],ch[2000005],cz[2000005],kkk[2000005];
bool flag;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        memset(qu,0,sizeof(l));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(l));
        memset(ch,0,sizeof(l));
        cnt1=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(i>1){
                if(x[i]-x[i-1]>d){
                    cnt1++;
                    qu[cnt1]=i;
                }
            }
            ch[i]=i;
        }
        cnt2=1;
        for(int i=2;i<=n;i++){
            while(x[i]-x[cnt2]>d){
                ch[cnt2]=i-1;
                cnt2++;
            }
        }
        while(cnt2<=n){
            ch[cnt2]=n;
            cnt2++;
        }
        cnt2=0;
        for(int i=1;i<=n-3;i++){
            if((ch[ch[i]-2]!=ch[ch[i]-1]&&ch[i]-i>2)||(ch[i]-i==2&&ch[i+1]>i+2)){
                if(r[cnt2]==ch[ch[i]-2]+1){
                    l[cnt2]=i;
                    continue;
                }
                cnt2++;
                l[cnt2]=i;
                r[cnt2]=ch[ch[i]-2]+1;
            }
        }
        int to1=1,to2=1;
        ans=0;
        for(int i=1;i<=cnt1+cnt2;i++){
            if((qu[to1]<=l[to2]&&to1<=cnt1)||to2>cnt2){
                cz[i]=to1;
                kkk[i]=0;
                to1++;
            }
            else{
                cz[i]=to2;
                kkk[i]=1;
                to2++;
            }
        }
        //for(int i=1;i<=n;i++) cout<<i<<"ch "<<ch[i]<<endl;
        for(int i=1;i<=cnt1;i++) cout<<"qu "<<qu[i]<<endl;
        for(int i=1;i<=cnt2;i++) cout<<"lr "<<l[i]<<" "<<r[i]<<endl;
        for(int i=1;i<=cnt1+cnt2;i++) cout<<kkk[i]<<" "<<cz[i]<<endl;
        for(int i=1;i<=cnt1+cnt2;i++){
            if(kkk[i]==1){
                if(cnt1+cnt2==1){
                    to1=l[1];
                    to2=n-r[1]+1;
                }
                else if(i==1){
                    to1=l[1];
                    if(kkk[i+1]==1){
                        to2=r[2]-r[1];
                    }
                    else{
                        to2=qu[1]-r[1];
                    }
                }
                else if(i==cnt1+cnt2){
                    to2=n-r[cnt2]+1;
                    if(kkk[i-1]==1){
                        to1=l[cnt2]-l[cnt2-1];
                    }
                    else{
                        to1=l[cnt2]-qu[cnt1]+1;
                    }
                }
                else{
                    if(kkk[i-1]==1){
                        to1=l[cz[i]]-l[cz[i-1]];
                    }
                    else{
                        to1=l[cz[i]]-qu[cz[i-1]];
                    }
                    if(kkk[i+1]==1){
                        to2=r[cz[i+1]]-r[cz[i]];
                    }
                    else{
                        to2=qu[cz[i+1]]-r[cz[i]];
                    }
                }
                ans+=to1*to2;
                cout<<i<<" "<<to1<<" "<<to2<<endl;
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
