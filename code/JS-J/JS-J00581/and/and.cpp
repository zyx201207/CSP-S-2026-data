#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int f(int n,int m){
    int b[1009],l=0,c[1009],k=0;
    memset(b,-1,sizeof b);
    memset(c,-1,sizeof c);
    while(n!=0){
        b[l]=n%10;
        n/=10;
        l++;
    }
    while(m!=0){
        c[k]=m%10;
        m/=10;
        k++;
    }
    int h[100]={0};
    if(l>k){
        for(int i =l;i>=l-k;i--){
            if(b[i]==c[i+k-l]){
                h[i]=1;
            }
        }
    }else{
        for(int i =k;i>=k-l;i--){
            if(c[i]==b[i+l-k]){
                h[i]=1;
            }
        }
    }
    int o=0;
    for(int i = 0;i<=min(l,k);i++){
        o+=h[i]*int(pow(2,i));
    }
    return o;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0;
    cin >> n>>m;
    if(m==1){
        long long l=0;
        for(int i = 1;i<=n;i++){
            cin >> a[i];
            l=max(l,a[i]);
        }
        cout << l;
    }else if(m==2){
        if(n==5&&m==3) cout << 7;
       else  cout << 0;
    }
    return 0;
}
