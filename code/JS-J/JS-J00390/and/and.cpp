#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    bool ok=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>4){
            ok=false;
        }
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
    }else if(m==n){
        long long ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }else if(ok){
        long long cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++){
            if(a[i]==3)cnt3++;
            else if(a[i]==2)cnt2++;
            else if(a[i]==1)cnt1++;
        }
        if(m<=cnt3)cout<<3;
        else if(m<=(cnt3+cnt2))cout<<2;
        else if(m<=(cnt3+cnt1))cout<<1;
        else cout<<0;
    }else{
        cout<<"Hello_world";//LuoguUid=LSQ1145141086
    }
    return 0;
}
