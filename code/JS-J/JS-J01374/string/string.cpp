#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,a[200005];
char zm[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>zm[i];
    }
    long long t=a[1];
    int wz=n;
    for(int i=1;i<=n;i++){
        t=a[i];
        if(i==wz){

            break;
        }
        while(i<wz){
            if(zm[i]!=zm[wz]){
                if(t>=a[wz]){
                    t-=a[wz];
                    ans+=a[wz];
                    wz--;
                }else{
                    a[wz]-=t;
                    ans+=t;
                    break;
                }
            }else{
                if(t>=a[wz]){
                    t-=a[wz];
                    wz--;
                }else{
                    a[wz]-=t;
                    break;
                }

            }
        }
    }
    cout<<ans;
    return 0;
}
