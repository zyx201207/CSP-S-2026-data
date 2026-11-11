#include<bits/stdc++.h>
#define maxn 200010
using namespace std;
int num[maxn];
char c[maxn];
int n;
long long len=0,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i]>>c[i];
        len+=num[i];
    }
    int l=1,r=n;
    while(l<r){
        if(c[l]==c[r]){
            if(num[l]==num[r]){
                if(num[l]==num[r]){
                    l++;
                    r--;
                }
            }else if(num[l]>num[r]){
                num[l]-=num[r];
                r--;
            }else{
                num[r]-=num[l];
                l++;
            }
        }else{
            if(num[l]==num[r]){
                ans+=num[l];
                l++;
                r--;
            }else if(num[l]>num[r]){
                ans+=num[r];
                num[l]-=num[r];
                r--;
            }else{
                ans+=num[l];
                num[r]-=num[l];
                l++;
            }
        }
    }
    cout<<ans<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}