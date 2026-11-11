#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000001],pd,sum,dp,l,r,ans[10000001],c,b,mid,mj,sz,sb;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==2){
            sz=a[i]-a[i-1];
        }
        else if(i!=1){
            if(a[i]-a[i-1]!=sz){
                pd=1;
            }
        }
    }
    sort(a+1,a+n+1);
    mid=(1+n)/2,c=mid-1,b=mid+1;
    if(!pd){
        while(c>=1||b<=n){
            if(c>=1&&b<=n){
                mj+=a[b]-a[c];
                sb+=2;
            }
            if(mj>m){
                if(mj-(abs(a[mid]-a[b]))>m){
                    sb-=2;
                    break;
                }
                else{
                    sb-=1;
                    break;
                }
            }
            c--,b++;
        }
        cout<<sb+1;
        return 0;
    }
    long long t=m;
    for(int i=1;i<=n;i++){
        l=i-1,r=i+1,t=m,sum=0;
        while(t--){
            if(l<1&&r>n){
                break;
            }
            if(l<1&&r<=n){
                if(sum+a[r]-a[i]<=m){
                    sum+=a[r]-a[i];
                    r++;
                    ans[i]++;
                }
                else{
                    break;
                }
            }
            else if(r>n&&l>=1){
                if(sum+a[i]-a[l]<=m){
                    sum+=a[i]-a[l];
                    l--;
                    ans[i]++;
                }
                else{
                    break;
                }
            }
            else if(l>=1&&r<=n){
                if(a[r]-a[i]>a[i]-a[l]){
                    if(sum+a[i]-a[l]<=m){
                        sum+=a[i]-a[l];
                        l--;
                        ans[i]++;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(sum+a[r]-a[i]<=m){
                        sum+=a[r]-a[i];
                        r++;
                        ans[i]++;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    sort(ans+1,ans+n+1);
    cout<<ans[n]+1;
    return 0;
}

