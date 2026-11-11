#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,len=0,nlen=0,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        len+=a[i];
    }
    len/=2;
    int l=0,r=n-1;
    while(nlen<=len){
        if(nlen+min(a[l],a[r])<len){
            if(b[l]==b[r]){
                if(a[l]>a[r]){
                    nlen+=a[r];
                    a[l]-=a[r];
                    r--;
                }else if(a[l]==a[r]){
                    nlen+=a[r];
                    l++; r--;
                }else{
                    nlen+=a[l];
                    a[r]-=a[l];
                    l++;
                }
            }else{
                if(a[l]>a[r]){
                    nlen+=a[r];
                    ans+=a[r];
                    a[l]-=a[r];
                    r--;
                }else if(a[l]==a[r]){
                    nlen+=a[r];
                    ans+=a[r];
                    l++; r--;
                }else{
                    nlen+=a[l];
                    ans+=a[l];
                    a[r]-=a[l];
                    l++;
                }
            }
        }else{
            if(b[l]==b[r]){
                break;
            }else{
                ans+=len-nlen;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
