#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=200005;
pair<int,char> str[maxn],l[maxn],r[maxn];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        if(c!=str[m].second || i==1){
            str[++m].first=a;
            str[m].second=c;
        }
        else
            str[m].first+=a;
    }
    int L=0,cur=0,ltot=0,rtot=0;
    bool flag=false;
    for(int i=1;i<=m;i++)
        L+=str[i].first;
    for(int i=1;i<=m;i++){
        cur+=str[i].first;
        if(!flag){
            if(cur>L/2){
                int x=str[i].first+L/2-cur,y=cur-(L+1)/2;
                if(x>0){
                    l[++ltot].second=str[i].second;
                    l[ltot].first=x;
                }
                if(y>0){
                    r[++rtot].second=str[i].second;
                    r[rtot].first=y;
                }
                flag=true;
            }
            else
                l[++ltot]=str[i];
        }
        else
            r[++rtot]=str[i];
    }
    int lst=0,ans=0;
    for(int i=1,j=rtot;i<=ltot;i++){
        int lsz=l[i].first,rsz=r[j].first;
        if(lsz<lst){
            if(l[i].second!=r[j].second)
                ans+=lsz;
            lst-=lsz;
            continue;
        }
        else if(lsz>=lst && lst>0){
            if(l[i].second!=r[j].second)
                ans+=lst;
            lsz-=lst,lst=0;
            j--,rsz=r[j].first;
        }
        while(rsz<lsz && j>=1){
            if(l[i].second!=r[j].second)
                ans+=r[j].first;
            j--;
            rsz+=r[j].first;
        }
        if(l[i].second!=r[j].second)
            ans+=lsz-rsz+r[j].first;
        lst=rsz-lsz;
        if(rsz==lsz)
            j--;
    }
    cout<<ans<<endl;
    return 0;
}
