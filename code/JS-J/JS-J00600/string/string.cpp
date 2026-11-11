#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200005];
char ch[200005];
ll sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
        sum+=a[i];
    }
    ll l=1,r=n,sl=0,sr=0,k=0;
    ll ans=0;
    sum=(sum+1)/2;
    while((sl<sum&&sr<sum)||(l<r)){
        if(sl+a[l]<=sr){
            sl+=a[l];
            if(ch[l]!=ch[r]){
                ans+=a[l];
            }
        }
        else if(sr+a[r]<=sl){
            sr+=a[r];
            if(ch[l]!=ch[r]){
                ans+=a[r];
            }
        }
        else{
            if(sl<sr){
                sl+=a[l];
                if(ch[l]!=ch[r]){
                    ans+=sr-sl+a[l];
                }
            }else if(sl>sr){
                sr+=a[r];
                if(ch[l]!=ch[r]){
                    ans+=sl-sr+a[r];
                }
            }else{
                sl+=a[l],sr+=a[r];
                if(ch[l]!=ch[r]){
                    ans+=min(a[l],a[r]);
                }
            }
        }
        if(sl<sr)l++;
        else if(sl>sr)r--;
        else l++,r--;
    }
    cout<<ans<<endl;
    return 0;
}
