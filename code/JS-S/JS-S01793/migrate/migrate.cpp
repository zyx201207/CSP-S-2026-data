#include <bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            long long n,d;
            cin>>n>>d;
            long long cnt=0,cha;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            cha=a[2]-a[1];
            for(int i=1;i<=n;i++){
                long long l=i,r=n,k;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(a[mid]-a[i]<=d){
                        l=mid+1;
                        k=mid;
                    }
                    else{
                        r=mid-1;
                    }
                }
                l=a[k-2]+d+1,r=min(a[k-1]+d,a[n]);
                long long shou=l/cha*cha+(l/cha*cha!=l)*cha;
                long long mo=r/cha*cha;
                long long xiang=(mo-shou)/cha+1;
                cnt+=xiang;
            }
            cout<<cnt<<"\n";
        }
        return 0;

    }
    while(t--){
        long long n,d;
        cin>>n>>d;
        memset(a,0,sizeof a);
        long long cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            long long l=i,r=n,k;
            while(l<=r){
                long long mid=(l+r)/2;
                if(abs(a[mid]-a[i])<=d){
                    l=mid+1;
                    k=mid;
                }
                else{
                    r=mid-1;
                }
            }
            //cout<<"K:"<<k<<'\n';
            if(k==i+1){
                continue;
            }
            l=a[k-2]+d+1,r=a[k-1]+d;
            for(int j=i+1;j<=n;j++){
                if(a[j]>r){
                    break;
                }
                else if(l<=a[j]&&r>=a[j]){

                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }


    return 0;
}
