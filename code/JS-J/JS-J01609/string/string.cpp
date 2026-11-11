#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,len,tl,tr,tw,tc,mid,a[500001],c[500001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        char sp,x;
        cin>>a[i]>>x;
        c[i]=x;
        len+=a[i];
    }
    mid=len/2;
    if(len%2==1){
        mid++;
    }
    //cout<<len<<' '<<mid<<"\n";
    for(int i=1;i<=n;i++){
        tl+=a[i];
        if(tl>=mid){
            tc=c[i];
            tw=i;
            break;
        }
    }
    if(len%2==1){
        long long lef=mid-(tl-a[tw])-1,rig=tl-mid;
        if(lef>rig){
            a[tw]=lef-rig;
            tr=tw+1;
            tl=tw;
        }
        if(lef==rig){
            a[tw]=0;
            tl=tw-1;
            tr=tw+1;
        }
        if(lef<rig){
            a[tw]=rig-lef;
            tl=tw-1;
            tr=tw;
        }
        //cout<<lef<<' '<<rig<<' '<<tl<<' '<<tr<<"\n";
        for(;tr<=n;tr++){
            long long tta=0;
            while(1){
                if(tta==a[tr]){
                    break;
                }
                if(tta>a[tr]){
                    tl++;
                    a[tl]=tta-a[tr];
                    break;
                }
                if(tl<1){
                    break;
                }
                if(c[tl]!=c[tr]){
                    ans+=a[tl];
                    if(tta+a[tl]>a[tr]){
                        ans-=tta+a[tl]-a[tr];
                    }
                }
                tta+=a[tl];
                tl--;
                //cout<<tl<<"\n";
            }
        }
    }
    else{
        long long lef=mid-(tl-a[tw]),rig=tl-mid;
        if(lef>rig){
            a[tw]=lef-rig;
            tr=tw+1;
            tl=tw;
        }
        if(lef==rig){
            a[tw]=0;
            tl=tw-1;
            tr=tw+1;
        }
        if(lef<rig){
            a[tw]=rig-lef;
            tl=tw-1;
            tr=tw;
        }
        for(;tr<=n;tr++){
            long long tta=0;
            while(1){
                if(tta==a[tr]){
                    break;
                }
                if(tta>a[tr]){
                    a[tl]=tta-a[tr];
                    break;
                }
                if(c[tl]!=c[tr]){
                    ans+=a[tl];
                    if(tta+a[tl]>a[tr]){
                        ans-=tta+a[tl]-a[tr];
                    }
                }
                tta+=a[tl];
                tl--;
            }
        }
    }
    cout<<ans;
}
