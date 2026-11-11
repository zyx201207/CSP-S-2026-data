
#include<bits/stdc++.h>
#define ll long long

using namespace std;
int n;
char c[200010];
ll a[200010],lin;
ll x[200010],y[200010],lx,ly,ans;
char cx[200010],cy[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        lin+=a[i];
    }
    ll sum=0;

    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(sum>lin/2){
            x[++lx]=lin/2-(sum-a[i]);
            cx[lx]=c[i];
            for(int j=n;j>i;j--){
                y[++ly]=a[j];
                cy[ly]=c[j];
            }
            y[++ly]=sum-lin/2;
            if(lin%2)y[ly]--;
            cy[ly]=c[i];
            break;
        }
        x[++lx]=a[i];
        cx[lx]=c[i];
    }
    if(!x[lx])lx--;
 //   for(int i=1;i<=lx;i++)cout<<x[i]<<' '<<cx[i]<<'\n';
 //   cout<<'\n';
  //  for(int i=1;i<=ly;i++)cout<<y[i]<<' '<<cy[i]<<'\n';
    ll pt=1,sx=0,sy=0;
    for(int i=1;i<=lx;i++){
        sx+=x[i];
        while(sy+y[pt]<=sx&&pt<=ly){
            if(cx[i]!=cy[pt])ans+=y[pt];
            sy+=y[pt];
            pt++;
        }
        if(cx[i]!=cy[pt])ans+=sx-sy;
        y[pt]-=sx-sy;
        sy=sx;
    //    cout<<ans<<'\n';
    }
    cout<<ans;
    return 0;
}
