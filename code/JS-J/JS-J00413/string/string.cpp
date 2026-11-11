#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int n,sum;
int a[maxn],c[maxn];
int check(int x,int y,int xx,int yy){
    return min(x,xx)-max(y,yy);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        char x;
        cin>>x;
        c[i]=x-'a'+1;
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    int i1,sum1=0,sum2=sum/2;
    if(sum%2==0){
        for(int i=1;i<=n;i++){
            sum1+=a[i];
            if(sum1>=sum/2){
               i1=i;
               sum1-=a[i];
               break;
            }
        }
        int ans=0;
        int l=sum2-sum1,r=a[i1]-l;
        int i=i1,j=i1;
        int lastl=0,lastr=0;
        while(l+r<sum){
            if(l<r){
                i--;
                lastl=l;
                l+=a[i];
                if(c[i]!=c[j]){
                    ans+=check(l,lastl,r,lastr);
                }
            }
            else{//l>=r
                j++;
                lastr=r;
                r+=a[j];
                if(c[i]!=c[j]){
                    ans+=check(l,lastl,r,lastr);
                }
            }

        }
        cout<<ans;
    }
//  int i1,sum1=0,sum2=sum/2;
    else{
        for(int i=1;i<=n;i++){
            sum1+=a[i];
            if(sum1>=sum/2){
               i1=i;
               sum1-=a[i];
               break;
            }
        }
        int ans=0;
        int l=sum2-sum1,r=a[i1]-l-1;
        int i=i1,j=i1;
        int lastl=0,lastr=0;
        while(l+r<sum){
            if(l<r){
                i--;
                lastl=l;
                l+=a[i];
                if(c[i]!=c[j]){
                    ans+=check(l,lastl,r,lastr);
                }
            }
            else{//l>=r
                j++;
                lastr=r;
                r+=a[j];
                if(c[i]!=c[j]){
                    ans+=check(l,lastl,r,lastr);
                }
            }

        }
        cout<<ans;
    }
    return 0;
}
