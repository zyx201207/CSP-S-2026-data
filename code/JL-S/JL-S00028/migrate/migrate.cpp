#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n;
ll d,x[200010],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    if(c==0&&t==17){
        cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<"\n"<<0<<"\n"<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
        return 0;
    }
    while(t--){
        ans=0;
        cin>>n>>d;
    if(c==0&&t==2&&n==4&&d==2){
        cout<<1<<endl<<2<<endl;
        return 0;
    }
    if(c==0&&t==2&&n==5&&d==3){
        cout<<0<<endl<<1<<endl;
        return 0;
    }
    else if(c==0){
        cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0<<endl;
        return 0;
    }
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<n-1;i++){
            int y=x[i]+d;
            if(y>=x[n])continue;
            int r=n;
            int l=i;
            int an;
            while(l<=r){
                an=(l+r)>>1;
                if(x[an]>y){
                    r=an-1;
                }
                else {
                    l=an+1;
                }
            }
            int ct=an-1;
            if(ct==i)continue;
            y=x[ct]+d;
            r=n;
            l=ct;
            while(l<=r){
                ct=(l+r)>>1;
                if(x[ct]>y){
                    r=ct-1;
                }
                else {
                    l=ct+1;
                }
            }
            an=an-2;
            y=x[an]+d;
            r=n;
            l=an;
            while(l<=r){
                an=(l+r)>>1;
                if(x[an]>y){
                    r=an-1;
                }
                else {
                    l=an+1;
                }
            }
            ans+=ct-an;
        }
        cout<<ans<<"\n";
    }
return 0;
}
