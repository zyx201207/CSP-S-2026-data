#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[200001];
char c[200001];
pair<ll,char> pre[200001];
pair<ll,char> post[200001];
int idx1=0,idx2=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        sum+=a[i];
    }
    ll sum1=0,sum2=0;
    for(int i=1;i<=n;i++){
        if(sum1==sum/2)break;
        if(sum1+a[i]>sum/2){
            pair<ll,char> p;
            p.first=sum/2-sum1;
            p.second=c[i];
            pre[++idx1]=p;
            break;
        }else{
            sum1+=a[i];
            pair<ll,char> p;
            p.first=a[i];
            p.second=c[i];
            pre[++idx1]=p;
        }
    }
    for(int i=n;i>=1;i--){
        if(sum2==sum/2)break;
        if(sum2+a[i]>sum/2){
            pair<ll,char> p;
            p.first=sum/2-sum2;
            p.second=c[i];
            post[++idx2]=p;
            break;
        }else{
            sum2+=a[i];
            pair<ll,char> p;
            p.first=a[i];
            p.second=c[i];
            post[++idx2]=p;
        }
    }

//    for(int i=1;i<=idx1;i++)cout<<pre[i].first<<pre[i].second;
//    cout<<'\n';
//    for(int i=1;i<=idx2;i++)cout<<post[i].first<<post[i].second;

    ll ans=0;
    int i=1,j=1;
    ll r1=pre[1].first,r2=post[1].first;
    while(i<=idx1&&j<=idx2){
        if(r1>r2){
            if(pre[i].second!=post[j].second){
                ans+=r2;
            }
            j++;
            r1-=r2;
            r2=post[j].first;
        }else if(r1==r2){
            if(pre[i].second!=post[j].second){
                ans+=r2;
            }
            i++;
            j++;
            r1=pre[i].first;
            r2=post[j].first;
        }else{
            if(pre[i].second!=post[j].second){
                ans+=r1;
            }
            i++;
            r2-=r1;
            r1=pre[i].first;
        }
    }
    cout<<ans;
    return 0;
}

