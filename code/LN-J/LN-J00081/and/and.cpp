#include<bits/stdc++.h>
using namespace std;
int a[200005];
int ans,maxn;
bool flag1,flag2;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
        if(a[i]>=4){
            flag1=1;
        }
        if(a[i]!=i-1){
            flag2=1;
        }
    }
    if(m==1){
        cout<<maxn<<endl;
    }else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans<<endl;
    }else if(m==2 && n<=2000){
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans<<endl;
    }else if(flag1==0){
        int aa=0,bb=0;
        for(int i=1;i<=n;i++){
            if(a[i]==3){
                aa++;
            }
            if(a[i]==2){
                bb++;
            }
            if(aa>=m){
                cout<<3<<endl;
            }else if(aa+bb>=m){
                cout<<2<<endl;
            }else{
                cout<<1<<endl;
            }
        }
    }else if(flag2==0 && n%2==0){
        int x=n;
        int k=0;
        while(x!=0){
            x/=2;
            k++;
        }
        k-=1;
        if(m==2){
            cout<<n-2<<endl;
        }
        else if(m>n-pow(2,k-1)){
            cout<<0<<endl;
        }
        else{
            ans=a[n];
            for(int i=n-1;i>n-m;i--){
                ans&=a[i];
            }
            cout<<ans<<endl;
        }
    }else{
        sort(a+1,a+1+n);
        ans=a[n];
        for(int i=n-1;i>n-m;i--){
            ans&=a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
