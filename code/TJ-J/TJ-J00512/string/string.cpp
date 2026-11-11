#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
typedef long long ll;
/*
signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    freopen("string.in","r",stdin);freopen("string.out","w",stdout);
    int n,tn;
    cin>>n;
    tn=n;
    vector<pair<int,char>> a(n+5);
    a[0]={0,'.'};
    int sum=0;
    for(int i=1;i<=n;i++){
        int t1;
        char t2;
        cin>>t1>>t2;
        sum+=t1;
        if(a[i-1].se==t2){
            a[i-1].fi+=t1;
            tn--;
        }else{
            a[i].fi=t1;
            a[i].se=t2;
        }
    }
    n=tn;
    int ans=0;
    int bpl=1,lastl=0,bpr=n,lastr=sum-a[n].fi;
    for(int l=1,r=sum-l+1;l!=r;l++,r=sum-l+1){
        char nl,nr;
        if(l-lastl>a[bpl].fi){
            bpl++;
            lastl=a[bpl].fi;
        }nl=a[bpl].se;
        if(r<=lastr){
            bpr--;
            lastr-=a[bpr].fi;
        }nr=a[bpr].se;
        if(nl!=nr) ans++;
    }
    cout<<ans;
    return 0;
}
*/
signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,tn;
    cin>>n;
    tn=n;
    vector<pair<int,char>> a(n+5);
    a[0]={0,'.'};
    int sum=0;
    for(int i=1;i<=tn;i++){
        int t1;
        char t2;
        cin>>t1>>t2;
        sum+=t1;
        if(a[i-1].se==t2){
            a[i-1].fi+=t1;
            tn--;
            i--;
        }else{
            a[i].fi=t1;
            a[i].se=t2;
        }//cout<<tn<<' '<<t1<<' '<<char(t2)<<' '<<a[i-1].fi<<' '<<char(a[i-1].se)<<endl;

    }
    n=tn;
    int ans=0;
    int diff=0;
    int bpl=1,lastl=0,bpr=n,lastr=sum-a[n].fi;
    for(int l=1,r=n;r!=l&&l<=n/2&&r>=n/2;l++,r=n-l+1){
        //cout<<l<<' '<<r<<endl;
        //cout<<a[l].fi<<' '<<r<<' '<<diff<<endl;
        if(diff-a[r].fi>=0){
            l--;
            diff-=a[r].fi;
        }else if(diff+a[l].fi<=0){
            r++;
            diff+=a[l].fi;
        }
        else if(a[l].se!=a[r].se){
            //cout<<a[l].fi<<' '<<a[r].fi<<' '<<l<<' '<<r<<' '<<n<<endl;
            diff+=a[l].fi-a[r].fi;
        }
        ans+=min(a[l].fi,a[r].fi);
    }
    cout<<ans;
}
