#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int N2=3e5+10;
int a[N],pos[N2];
int main (){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=5&&m<=2){
        int ans1=0,ans2=0;
        for(int i=1;i<=n;i++){
            int cnt1=0,cnt2=0;

                if(a[i]==1)cnt1++;
                if(a[i]==2)cnt2++;
                if(a[i]==1&&cnt1!=0){
                    for(int k=i;k>=1;k--){
                        if(a[k]==1)break;
                        if(a[k]==2)cnt2--;
                    }
                }
                if(a[i]==2&&cnt2!=0){
                    for(int k=i;k>=1;k--){
                        if(a[k]==1)cnt1--;
                        if(a[k]==2)break;
                    }
                }

            if(cnt1>0)ans1++;
            if(cnt2>0)ans2++;
        }cout<<ans1<<" "<<ans2<<endl;
    }

    return 0;
}
