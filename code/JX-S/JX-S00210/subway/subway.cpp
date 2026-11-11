#include<bits/stdc++.h>
using namespace std;
bool f;
long long n,m,a[500005],ma=-1,mas=-2000000,mis=2000000;
long long s[200005],ss[200005],su,la,las,shu;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    //if(m>100000000){
    //}
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=100000;
        mas=max(a[i],mas);
        mis=min(a[i],mis);
        s[a[i]]++;
        ss[a[i]]++;
    }
    for(long long i=mas;i>=mis;i--){
        la=su;
        for(long long j=s[i];j>=0;j--){
            su+=i;
            s[i]--;
            shu++;
            if(su>m){
                break;
            }
        }
        cout<<su<<" "<<shu<<endl;
        if(su>m){
            las=i;
            su=la;
            shu-=s[i];
            break;
        }
    }
    ma=shu;
    for(long long i=mas-1;i>=mis;i--){
        shu-=ss[i+1];
        su-=shu;
        cout<<su<<" "<<shu<<endl;
        if(su<m){
            f=0;
            for(long long j=las;j>=0;j--){
                if(s[j]>0){
                    for(long long z=s[j];z>=0;z--){
                        su+=j;
                        s[j]--;
                        shu++;
                        if(su>m)break;
                    }
                    ma=max(shu,ma);
                    las=j;
                    f=1;
                    if(su>m)break;
                }
            }
        }
        if(f==0)break;
    }
    cout<<ma;
    return 0;
}
