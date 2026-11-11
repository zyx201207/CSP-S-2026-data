#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxN=300010;
int n,m,a[maxN],ina[maxN],l,r,sum,ans,z;
char inc[maxN],c[maxN];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ina[i]>>inc[i];
        sum+=ina[i];
    }
    m=n;
    if(sum%2==1){
        for(int i=1,cnt=0;i<=n;i++){
            cnt+=ina[i];
            if(cnt>=(sum+1)/2){
                ina[i]--;
                break;
            }
        }
    }
    for(int i=1,j=1,cnt=0;i<=n&&j<=m;i++,j++){
        cnt+=ina[i];
        if(z==0&&cnt>sum/2) z=i-1;
        if(cnt>sum/2&&cnt-ina[i]+1<=sum/2){
            a[j]=ina[j]-(cnt-sum/2);
            c[j]=inc[j];
            j++,m++;
            a[j]=cnt-sum/2,c[j]=inc[j-1];
        }
        else a[j]=ina[i],c[j]=inc[i];
    }
    //cout<<z<<endl;
    for(l=1,r=1;l<=z;){
        //cout<<l<<' '<<m-r+1<<endl;
        if(c[l]!=c[m-r+1]){
            //cout<<"No,a[l] is "<<a[l]<<" a[m-r+1] is "<<a[m-r+1];int aaa=ans;
            if(a[l]>a[m-r+1]) ans+=a[m-r+1],a[l]-=a[m-r+1],r++;
            else if(a[l]<a[m-r+1]) ans+=a[l],a[m-r+1]-=a[l],l++;
            else ans+=a[l],l++,r++;
            //cout<<".And ans+"<<ans-aaa<<endl;
        }
        else{
            //cout<<"yes"<<endl;
            if(a[l]>a[m-r+1]) a[l]-=a[m-r+1],r++;
            else if(a[l]<a[m-r+1]) a[m-r+1]-=a[l],l++;
            else l++,r++;
        }
    }
    cout<<ans;
    return 0;
}