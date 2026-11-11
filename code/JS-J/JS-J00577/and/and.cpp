#include<bits/stdc++.h>
using namespace std;
const int MAX=200005;
int a[MAX];
int num=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    bool huo=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            huo=0;
        }
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    if(huo==0 and m==n){
        cout<<0;
        return 0;
    }
    for(int i=n;i>=1;i--){
        if(a[i]%2==1){
            int i=1;
            while(1){
                i*=2;
                if(i<=a[i] or i-1>a[i]){
                    continue;
                }
                if(i-1>a[i]){
                    break;;
                }
                if(i-1==a[i]){
                        a[i]*=-1;
                    break;
                }
            }
        }
    }
    sort(a+1,a+n+1);
    for(int i=1;i<m;i++){
        if(a[i]<0){
            if(a[i+1]<0){
                continue;
            }
            else{
                int x=0-a[i];
                if(num==0){
                    num=x;
                }else if(i+1==m){
                    num&x;
                }
            }
        }
    }
    cout<<num;
    return 0;
}
