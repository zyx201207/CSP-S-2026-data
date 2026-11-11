#include<bits/stdc++.h>
using namespace std;
long long a[5000010],ans;
char c[5000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    if(sum<=100000000){
        string s="\0";
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i];j++){
                s+=c[i];
            }
        }
        for(int i=0;i<sum;i++){
            if(s[i]!=s[sum-i-1]){
                ans++;
                s[sum-i-1]=s[i];
            }
        }
        cout<<ans;
        return 0;
    }
    long long sum_mid=(sum+1)/2;
    long long tot=0,cnt=0;
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(tot<sum_mid&&tot+a[i]>=sum_mid){
            if(a[i]==1){
                flag=false;
                break;
            }
            cnt=1ll*i;
            break;
        }else{
            tot+=a[i];
        }
    }
    if(flag&&sum%2==0){
        for(int i=n;i>cnt;i--){
            a[i+1]=a[i];
            c[i+1]=c[i];
        }
        a[cnt+1]=a[cnt]-sum_mid+tot;
        a[cnt]-=a[cnt+1];
        c[cnt+1]=c[cnt];
        n++;
    }else if(flag&&sum%2==1){
        for(int i=n;i>=0;i--){
            a[i+1]=a[i];
            c[i+1]=c[i];
        }
        cnt++;
        n++;
        for(int i=n;i>cnt;i--){
            a[i+1]=a[i];
            c[i+1]=c[i];
        }
        for(int i=1;i<=cnt-1;i++){
            a[i-1]=a[i];
            c[i-1]=c[i];
        }
        a[cnt-1]=sum_mid-tot-1;
        a[cnt+1]=a[cnt]-a[cnt-1]-1;
        a[cnt]=a[cnt]-a[cnt-1]-a[cnt+1];
        c[cnt+1]=c[cnt];
        c[cnt-1]=c[cnt];
        n++;
    }
    if(n%2==1){
        int l=1,r=n;
        int mid=(n+1)/2;
        while(l<mid&&r>mid){
            if(c[l]!=c[r]){
                if(a[r]<a[l]){
                    ans+=a[r];
                    a[l]-=a[r];
                    r--;
                }else if(a[r]==a[l]){
                    ans+=a[r];
                    l++,r--;
                }else if(a[r]>a[l]){
                    ans+=a[l];
                    a[r]-=a[l];
                    l++;
                }
            }else{
                if(a[l]>a[r]){
                    r--;
                }else if(a[l]==a[r]){
                    l++,r--;
                }else{
                    l++;
                }
            }
        }
    }else{
        int mid1=n/2,mid2=n/2+1;
        int l=1,r=n;
        while(l<mid1&&r>mid2){
            if(c[l]!=c[r]){
                if(a[r]<a[l]){
                    ans+=a[r];
                    a[l]-=a[r];
                    r--;
                }else if(a[r]==a[l]){
                    ans+=a[r];
                    l++,r--;
                }else if(a[r]>a[l]){
                    ans+=a[l];
                    a[r]-=a[l];
                    l++;
                }
            }else{
                if(a[l]>a[r]){
                    r--;
                }else if(a[l]==a[r]){
                    l++,r--;
                }else{
                    l++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}