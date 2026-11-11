#include<bits/stdc++.h>
using namespace std;
long long a[100001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long m,ans=0,c;
    int n,x=0,y=0,h=0,cnt=0;
    bool p=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    c=a[2]-a[1];
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]!=c){
            p=0;
        }
    }
    if(p==1){
        if(c==0){
            cout<<n;
        }else{
            for(int i=1;i<=n;i++){
                if(m>=c){
                    m-=c;
                    h++;
                }
                c+=1;
            }
            cout<<h;
        }
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            h=0;
            for(int k=i;k<=j;k++){
                h+=a[j]-a[k];
            }
            if(h<=m&&j-i+1>cnt){
                    ans=h;
                    x=i;
                    y=j;
                    cnt=y-x+1;
                }
        }
    }
    cout<<cnt;
    return 0;
}
