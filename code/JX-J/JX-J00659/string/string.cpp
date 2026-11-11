#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long a[N],ans=0;
char b[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","W",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    long long i=1,j=n;
    while(i<=j){
        if(b[i]==b[j]){
            if(a[i]==a[j]){
                i++;
                j--;
                continue;
            }else if(a[i]>a[j]){
                a[i]-=a[j];
                j--;
                continue;
            }else{
                a[j]-=a[i];
                i++;
                continue;
            }
        }else{
            if(a[i]==a[j]){
                ans+=a[i];
                i++;
                j--;
                continue;
            }else if(a[i]>a[j]){
                ans+=a[j];
                a[i]-=a[j];
                j--;
                continue;
            }else{
                ans+=a[i];
                a[j]-=a[i];
                i++;
                continue;
            }
        }
    }
    cout<<ans;
    return 0;
}
