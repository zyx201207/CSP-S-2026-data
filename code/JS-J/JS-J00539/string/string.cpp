#include<bits/stdc++.h>
using namespace std;
long long cnt[200005],n,tn,nw=1,ans=0;
char a[200005],t;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tn>>t;
        if(i==1)a[nw]=t,cnt[nw]+=tn;
        //cout<<' '<<a[nw]<<endl;
        else if(t==a[nw])cnt[nw]+=tn;
        else nw++,a[nw]=t,cnt[nw]=tn;
    }int l=1,r=nw;
    //cout<<nw<<endl;
    while(l<r){
        if(cnt[l]==0)l++;
        if(cnt[r]==0)r--;
        //cout<<"l:"<<l<<' '<<cnt[l]<<" r:"<<r<<' '<<cnt[r]<<" now:"<<nw<<" nowans:"<<ans<<endl;
        long long tmp=min(cnt[l],cnt[r]);
        if(a[l]!=a[r])ans+=tmp;
        cnt[l]-=tmp,cnt[r]-=tmp;
    }
    cout<<ans;
    return 0;
}

/*
2
2 a
3 a

3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
