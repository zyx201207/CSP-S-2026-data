#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long tot;
char c[200005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        tot+=a[i];
    }
    int l=1,r=n;
    long long mid=tot/2,ans=0;
    while(l<r){
        if(a[l]==a[r]){
            if(c[l]!=c[r])ans+=a[l];
            l++,r--;
            continue;
        }
        else{
            if(a[l]<a[r]){
                if(c[l]!=c[r]){
                    ans+=a[l];
                    //a[r]-=a[l++];
                }
                a[r]-=a[l++];
                //ans--;
            }
            else{
                if(c[l]!=c[r]){
                    ans+=a[r];
                    //a[r]-=a[l++];
                }
                a[l]-=a[r--];
            }
        }
    }
    cout<<ans;
	return 0;
}
