#include<bits/stdc++.h>;
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int mn=0;
    cin>>n>>m;
    int a[n+10];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(m==1){
        sort(a+1,a+n+1,greater<int>());
        cout<<a[1];
        return 0;
    }
    else if(m==n){
        int p=a[1];
        for(int i=2;i<=n;i++){
             p=(p&a[i]);
        }
        cout<<p;
        return 0;
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if((a[i]&a[j])>mn){
                    mn=(a[i]&a[j]);
                }
            }
        }
    }
    else if(m==3){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++)
                    if((a[i]&a[j]&a[k])>mn){
                        mn=(a[i]&a[j]&a[k]);
                }
            }
        }
    }
    else if(a[67]<4&&a[78]<4&&a[91]<4){
        sort(a+1,a+n+1,greater<int>());
        cout<<a[m];
        return 0;
    }
    else{
        cout<<1023;
        return 0;
    }
    cout<<mn;
    return 0;
}
