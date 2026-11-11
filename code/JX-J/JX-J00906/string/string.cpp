#include<bits/stdc++.h>
using namespace std;
long long n,a[100000000],ans,js=0,sum=1;
char c[100000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        if(n<=1){
            cout<<0;
            return 0;
        }
        if(c[i]!=c[i+1]){
            break;
        }
        if(i==n-1){
            cout<<0;
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            if(n%2==0){
                if(i+1==j){
                    cout<<ans;
                    return 0;
                }
            }
            else{
                if(i==j){
                    cout<<ans;
                    return 0;
                }

            }
            if(a[i]>=a[j]&&c[i]!=c[j]){
                ans+=a[j];
                a[i]-=a[j];
                js++;
            }
            else{
                if(c[i]!=c[j]){
                    ans+=a[j];
                    a[j]-=a[i];
                    i++;
                }
            }
            if(a[i]==a[j]){
                break;
            }
        }
    }
    return 0;
}
