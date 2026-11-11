#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> a[5000010];
long long tmp[5000010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>tmp[i];
    }
    sort(tmp+1,tmp+1+n);
    int cnt=1;
    a[cnt]={tmp[1],1};
    for(int i=2;i<=n;i++){
        if(tmp[i]!=tmp[i-1]){
            a[++cnt].first=tmp[i];
        }
        a[cnt].second++;
    }
//    for(int i=1;i<=cnt;i++){
//        cout<<a[i].first<<" "<<a[i].second<<endl;
//    }
    long long ans=-1;
    for(int i=1;i<=cnt;i++){
        long long anstmp=0;
        long long mtmp=m;
        for(int j=i;j>=1;j--){
            if(mtmp>=(a[i].first-a[j].first)*a[j].second){
                anstmp+=a[j].second;
                mtmp-=(a[i].first-a[j].first)*a[j].second;
                if(i==4900){
 //                   cout<<i<<" "<<j<<" "<<anstmp<<" "<<mtmp<<" "<<a[i].first<<" "<<a[j].first<<" "<<a[i].first-a[j].first<<" "<<a[j].second<<endl;
                }
 //               cout<<i<<" "<<j<<" "<<anstmp<<endl;
            }
            else{
                anstmp+=floor(mtmp/(a[i].first-a[j].first));
//                if(i==4900){
//                    cout<<floor(mtmp/(a[i].first-a[j].first)<<" "<<anstmp;
//                }
//              cout<<i<<" "<<j<<" "<<anstmp<<endl;
                break;
            }
        }
//        cout<<anstmp<<" "<<" "<<i<<endl;
        ans=max(ans,anstmp);
    }
    cout<<ans;
    return 0;
}
