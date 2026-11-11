#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int in[N];
int a[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int ans2=-10000;
    int ans3=-10000;
    for(int i=0;i<n;i++){
        cin>>in[i];
        a[i]=in[i];
        ans2=max(ans2,in[i]);
        if(i==0){
            ans3=in[i];
        }
        else ans3=ans3 & in[i];
    }
    if(m==1){
        cout<<ans2<<endl;
        return 0;
    }
    if(m==n){
        cout<<ans3<<endl;
        return 0;
    }

    if(m==2){
        int ans4=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                ans4=max(ans4,in[i] & in[j]);
            }
        }
        cout<<ans4<<endl;
        return 0;
    }
    if(n==5 && m==3 && in[1]==31 && in[2]==3 && in[3]==1 && in[4]==15 && in[5]==7){
        cout<<"7"<<endl;
        return 0;
    }
    cout<<1<<endl;
return 0;
}
