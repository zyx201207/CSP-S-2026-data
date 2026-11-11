#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool check(int n){
    for(int i=1;i<=1024*1024*2;i*=2){
        if(n==i)return true;
    }
    return false;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    bool f=true;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    if(m==1){
        int maxx=-1;
        for(int i=0;i<n;i++)maxx=max(maxx,a[i]);
        cout<<maxx;
        f=false;
    }
    else{
        if(m==2){
            int maxx2=-1;
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++)
                    maxx2=max(maxx2,(a[i]&a[j]));
            }
            cout<<maxx2;
        }
        else{
            if(m==n){
                int ans=a[0];
                for(int i=0;i<n;i++)
                    ans=ans&a[i];
                cout<<ans;
            }
            else{
                int maxx3=-1;
                for(int i=0;i<n;i++)
                    maxx3=max(maxx3,a[i]);;
                if(maxx3<4){
                    sort(a,a+n);
                    int cnt1=0,cnt2=0,cnt3=0;
                    for(int i=0;i<n;i++){
                        if(a[i]==1)cnt1++;
                        if(a[i]==2)cnt2++;
                        if(a[i]==3)cnt3++;
                    }
                    if(cnt3>=m)cout<<3;
                    else{
                        if(cnt3+cnt2>=m)cout<<2;
                        else{
                            if(cnt1+cnt3>=m)cout<<1;
                            else cout<<0;
                        }
                    }
                }
                else{
                    sort(a,a+n);
                    cout<<a[m-1];
                }
            }
        }
    }


    return 0;
}
