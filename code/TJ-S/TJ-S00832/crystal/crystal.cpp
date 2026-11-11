#include<bits/stdc++.h>
using namespace std;
long long a[1111111],n,cnt=0,c=1,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==i){
            cnt++;
        }
    }
    if(cnt==n){
        for(int i=2;i<=n;i++){
            m-=i-1;
            if(m<0){
                break;
            }
            c++;
        }
        cout<<c;
        return 0;
    }else{
        for(int i=1;i<=n-1;i++){
            if(a[i]==a[i+1]){
                c++;
            }else if(m>=a[i+1]-a[i]&&m>=a[i]-a[i+1]){
                c++;
                if(a[i+1]>a[i]){
                    m-=a[i+1]-a[i];
                    a[i]+=a[i+1]-a[i];
                }else if(a[i+1]<a[i]){
                    m-=a[i]-a[i+1];
                    a[i+1]+=a[i]-a[i+1];
                }
            }else{
                cout<<c;
            return 0;
            }
        }
        cout<<c;
    }

    return 0;
}
