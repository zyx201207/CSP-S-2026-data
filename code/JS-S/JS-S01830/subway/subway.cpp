#include<bits/stdc++.h>
using namespace std;
int a[500005];
int x1[500005];
int y[500005];
int x2[500005];
int y2[500005];
int main(){
    freopen("subway1.in","r",stdin);
    freopen("subway.out","w",stdout);
int n,m,d,q,c;
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++){
    cin>>a[i];
}
int k1,k2;
if(n==2){
        cin>>k1;
    for(int i=1;i<=k1;i++){
        cin>>x1[i]>>y[i];
    }
         cin>>k2;
    for(int i=1;i<=k2;i++){
        cin>>x2[i]>>y2[i];
    }
}
int mn=2000000001;
for(int i=1;i<=k1;i++){
    for(int j=1;j<=k2;j++){
        if(x1[i]==x2[j]){
            mn=min(mn,y[i]+y2[j]);
        }
    }
}
while(q--){
    int f,e,c1=0,c2=0,c3=0,c4=0,ans=1000000;
    cin>>f>>e;
    for(int i=1;i<=k1;i++){
        if(x1[i]==f){
            c1=i;
        }
        if(x1[i]==e){
            c3=i;
        }
        if(x2[i]==f){
            c2=i;
        }
        if(x2[i]==e){
            c4=i;
        }
    }
    if(c1&&c3){
        ans=min(a[f]+a[e]+y[c1]+y[c3],ans);
    }
    if(c2&&c4){
        ans=min(a[f]+a[e]+y2[c2]+y2[c4],ans);
    }
    if(c1&&c4&&(!c2)&&(!c3)){
    ans=min(ans,mn+a[f]+a[e]+y[c1]+y2[c4]);
    }
    if(c2&&c3&&(!c1)&&(!c4)){
        ans=min(ans,mn+a[f]+a[e]+y2[c2]+y[c3]);
    }
    cout<<ans<<endl;
}
return 0;
}
