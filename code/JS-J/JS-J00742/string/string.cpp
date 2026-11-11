#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0;
    cin>>n;
    int num[200005];
    char a[200005];
    for(int i=1;i<=n;i++){
        cin>>num[i]>>a[i];
    }
    int l=1,r=n;
    while(r>=l){
        if(a[l]==a[r]){
            if(num[l]>num[r]){
                num[l]-=num[r];
                r--;
            }
            else if(num[l]<num[r]){
                num[r]-=num[l];
                l++;
            }
            else{
                l++;
                r--;
            }
        }
        else {

            if(num[l]>num[r]){
                num[l]-=num[r];
                ans+=num[r];
                r--;
            }
            else if(num[l]<num[r]){
                num[r]-=num[l];
                ans+=num[l];
                l++;
            }
            else{
                ans+=num[l];
                l++;
                r--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
