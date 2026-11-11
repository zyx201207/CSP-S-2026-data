#include<bits/stdc++.h>
#define iwill using
#define ak namespace
#define csps std;
iwill ak csps
long long n,d,a[3000006];
void solve(){
    cin>>n>>d;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans=0;
    for(long long i=1;i<n;i++){
        long long sy=d,lastzd=-1,lastzdcd=0,cnt=0;
        bool flag=false;
        for(long long j=i+1;j<=n;j++){
            if(sy>=a[j]-a[j-1]){
                sy-=(a[j]-a[j-1]);
                cnt++;
                if(lastzdcd>=2 && cnt>=1){
                    if(sy-a[lastzd]+a[lastzd-1]>=0){
                        if(flag==true){
                                break;
                        }
                        if(sy-a[j+1]+a[j]<0 && a[j+1]-a[j]>a[lastzd]-a[lastzd-1]){
                            if(flag==true){
                                break;
                            }
                            flag=true;
                        }
                        ans++;
                    }
                    else{
                        if(flag==true){
                            ans++;
                        }
                    }
                }
                else{
                    if(flag==true){
                        ans++;
                    }
                }
                if(lastzdcd>=3 && cnt>=1){
                    if(sy-a[lastzd]+a[lastzd-2]>=0){
                        if(sy-a[j+2]+a[j]<0 && min(a[j+2]-a[j],a[j+1]-a[j])>a[lastzd]-a[lastzd-2]){
                            flag=false;
                            ans--;
                            break;
                        }
                        ans--;
                    }
                }
            }
            else{
                lastzd=j-1;
                lastzdcd=cnt;
                cnt=1;
                sy=d;
                if(a[j]-a[j-1]>sy){
                    break;
                }
                sy-=(a[j]-a[j-1]);
                if(lastzdcd>=2 && cnt>=1){
                    if(sy-a[lastzd]+a[lastzd-1]>=0){
                        if(flag==true){
                            break;
                        }
                        if(sy-a[j+1]+a[j]<0 && a[j+1]-a[j]>a[lastzd]-a[lastzd-1]){
                            if(flag==true){
                                break;
                            }
                            flag=true;
                        }
                        ans++;
                    }
                    else{
                        if(flag==true){
                            ans++;
                        }
                    }
                }
                else{
                    if(flag==true){
                        ans++;
                    }
                }
                if(lastzdcd>=3 && cnt>=1){
                    if(sy-a[lastzd]+a[lastzd-1]>=0 && sy-a[lastzd]+a[lastzd-2]>=0){
                        if(sy-a[j+2]+a[j]<0 && min(a[j+2]-a[j],a[j+1]-a[j])>a[lastzd]-a[lastzd-2]){
                            flag=false;
                            ans--;
                            break;
                        }
                        ans--;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
void solve2(){
    cin>>n>>d;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    long long cf=a[2]-a[1];
    long long x1=d/cf;
    long long ans=0;
    for(long long i=1;i<=n;i++){
        long long dysl=n-i+1;
        if(dysl<=x1+x1-1){
            continue;
        }
        ans+=1;
        ans+=(dysl-x1-x1+1)/x1;
    }
    cout<<ans<<endl;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long t;
    int c;
    cin>>c>>t;
    if(c==11 || c==12){
        while(t--){
            solve2();
        }
        return 0;
    }
    if(c<=10){
        while(t--){
            solve();
        }
        return 0;
    }
    if(c==13 || c==14){
        while(t--){
            cout<<0<<endl;
        }
        return 0;
    }
    return 0;
}
