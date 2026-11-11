#include<bits/stdc++.h>
using namespace std;
int n;
long long x[200010];
char a[200010];
long long ans=0;
int main(){
    freopen("string.in", "r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>a[i];
    }
    int l=1;
    int r=n;
    while(l<=r){
            if(a[l]==a[r]){
                if(x[l]>x[r]){
                    x[l]-=x[r];
                    r--;
                }else if(x[l]<x[r]){
                    x[r]-=x[l];
                    l++;
                }else{
                    l++;r--;
                }
            }else{
                if(x[l]>x[r]){
                    ans+=x[r];
                    x[l]-=x[r];
                    r--;
                }else if(x[l]<x[r]){
                    ans+=x[l];
                    x[r]-=x[l];
                    l++;
                }else{
                    ans+=x[r];
                    l++;r--;
                }
            }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
