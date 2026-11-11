#include <bits/stdc++.h>
using namespace std;
constexpr int N=200005;
int n;
pair<long long,char> ar1[N],ar2[N];
long long sum,tmp=0,ans,sm1,sm2;
int ed1,ed2,idx1,idx2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>ar1[i].first>>ar1[i].second;
        ar2[i]=ar1[i];
        sum+=ar1[i].first;
    }
    reverse(ar2,ar2+n);
    for (int i=0;i<n;i++){
        if (tmp+ar1[i].first>=sum/2+(sum&1)){ar1[i].first=sum/2+(sum&1)-tmp;ed1=i;break;}
        tmp+=ar1[i].first;
    }
    tmp=0;
    for (int i=0;i<n;i++){
        if (tmp+ar2[i].first>=sum/2+(sum&1)){ar2[i].first=sum/2+(sum&1)-tmp;ed2=i;break;}
        tmp+=ar2[i].first;
    }
    for (;idx1<=ed1 && idx2<=ed2;){
        if (ar1[idx1].second!=ar2[idx2].second){
                ans+=min(sm1+ar1[idx1].first,sm2+ar2[idx2].first)-max(sm1,sm2);
        }
        if (sm1+ar1[idx1].first==sm2+ar2[idx2].first){
            sm1+=ar1[idx1].first;
            sm2+=ar2[idx2].first;
            idx1++;idx2++;
        }else if (sm1+ar1[idx1].first>sm2+ar2[idx2].first){
            sm2+=ar2[idx2].first;
            idx2++;
        }else{
            sm1+=ar1[idx1].first;
            idx1++;
        }
    }
    cout<<ans;
    cout<<'\n';
    return 0;
}
