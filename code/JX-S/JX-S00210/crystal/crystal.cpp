#include<bits/stdc++.h>
using namespace std;
bool f;
long long n,m,a[500005],ma=-1,mas=-2000000,mis=2000000;
long long s[200005],su,la,las,shu;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    if(m==0||n==0){
        cout<<0;
        return 0;
    }
    if(m>1000000000){
        for(long long i=1;i<=n;i++){
            cin>>a[i];
        }
        for(long long i=1;i<=n;i++){
            if(su+i<=m){
                su+=i;
            }
            la=i;
        }
        cout<<la;
        return 0;
    }
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=100000;
        mas=max(a[i],mas);
        mis=min(a[i],mis);
        s[a[i]]++;
    }
    for(long long i=mas;i>=mis;i--){
        la=su;
        su+=(mas-i)*s[i];
        shu+=s[i];
        //cout<<su<<" "<<shu<<endl;
        if(su>m){
            las=i;
            su=la;
            shu-=s[i];
            break;
        }
    }
    ma=shu;
    for(long long i=mas;i>=mis;i--){
        shu-=s[i+1];
        su-=shu;
        //cout<<su<<" "<<shu<<endl;
        if(su<m){
            //shu+=s[las];
            //ma=max(shu,ma);
            f=0;
            for(long long j=las-1;j>=0;j--){
                if(s[j]>0){
                    if(su+s[j]*(i-j)>m){
                        su+=s[j]*(i-j);
                        las=j;
                        shu+=s[las];
                        ma=max(shu,ma);
                        f=1;
                        if(su>m)break;
                    }
                }
            }
        }
        if(f==0)break;
    }
    cout<<ma;
    return 0;
}
