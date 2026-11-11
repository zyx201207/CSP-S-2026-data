#include<bits/stdc++.h>
using namespace std;
long long arr[200005];
char ar[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i] >> ar[i];
    }
    int l=1,r=n;
    char pre;
    long long cnt=0;
    long long ans=0;
    while(l<=r){
        if(cnt){
            while(l<=r&&cnt){
                char x=ar[r];
                if(cnt>=arr[r]){
                    cnt-=arr[r];
                    if(x!=pre){
                        ans+=arr[r];
                    }
                    r--;
                }
                else{
                    if(x!=pre){
                        ans+=cnt;
                    }
                    arr[r]-=cnt;
                    cnt=0;
                }
            }
        }
        else{
            cnt+=arr[l];
            pre=ar[l];
            l++;
        }
    }
    cout << ans;
    return 0;
}
