#include <bits/stdc++.h>
using namespace std;
long long n,a[200005];
long long sum,ans;
char c[200005];
pair<int,char> lef[200005],righ[200005];
int h1=1,h2=1,t1,t2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    if(sum%2==0){
        long long le=0;
        for(int i=1;i<=n;i++){
            le+=a[i];
            if(le>sum/2){
                if(sum/2+a[i]-le!=0){
                    t1++;
                    lef[t1].first=sum/2+a[i]-le;
                    lef[t1].second=c[i];
                }
                t2++;
                righ[t2].first=le-sum/2;
                righ[t2].second=c[i];
                for(int j=i+1;j<=n;j++){
                    t2++;
                    righ[t2].first=a[j];
                    righ[t2].second=c[j];
                }
            }else{
                t1++;
                lef[t1].first=a[i];
                lef[t1].second=c[i];
            }
        }
    }else{
        long long le=0;
        for(int i=1;i<=n;i++){
            le+=a[i];
            if(le>sum/2){
                if(sum/2+a[i]-le>0){
                    t1++;
                    lef[t1].first=sum/2+a[i]-le;
                    lef[t1].second=c[i];
                }

                if(le-sum/2-1>0){
                    t2++;
                    righ[t2].first=le-sum/2-1;
                    righ[t2].second=c[i];
                }
                for(int j=i+1;j<=n;j++){
                    t2++;
                    righ[t2].first=a[j];
                    righ[t2].second=c[j];
                }
                break;
            }else{
                t1++;
                lef[t1].first=a[i];
                lef[t1].second=c[i];
            }
        }
    }
    while(t1>=h1&&t2>=h2){
        if(lef[t1].second!=righ[h2].second){
            ans+=min(lef[t1].first,righ[h2].first);
        }
        lef[t1].first-=min(lef[t1].first,righ[h2].first);
        righ[h2].first-=min(lef[t1].first,righ[h2].first);
        if(lef[t1].first==0) t1--;
        if(righ[h2].first==0) h2++;//for(int i=1;i<=t2;i++) cout<<righ[i].first<<' '<<righ[i].second<<endl;
        //cout<<h2<<' '<<righ[h2].first<<endl;
    }
    cout<<ans;

    return 0;
}
