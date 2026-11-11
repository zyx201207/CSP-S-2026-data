#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500000+10],sum,mid,cnt,tmid,tm;
bool b;
bool cmp(long long a,long long b){
    return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    mid=n/2+1;
    tmid=mid;
    mid=a[mid];
    for(int i=0;i<=tmid-1;i++){
        if(m>=0){

            if(m>=mid-a[tmid-i]&&!b){
                    cnt++;
                    m-=mid-a[tmid-i];
            }
            if(i==tmid-1&&m-(a[tmid+1]-a[tmid])*tmid>=0&&tmid!=n){
                 b=true;
                  cnt++;
                tmid++;
                mid=a[tmid];
                m-=(a[tmid]-a[tmid-1])*(tmid-1);


                continue;
            }

        }else{
            break;
        }
    }
    cout<<cnt;
    return 0;
}

