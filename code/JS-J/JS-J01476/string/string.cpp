#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int n;
long long a[MAXN];
char c[MAXN];
long long len=0;
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
    }
    int i=1,j=n;
    while(i<=j){
        if(c[i]==c[j]){//be the same
            if(a[i]<a[j]){
                i++;
                a[j]-=a[i];
            }
            else if(a[i]>a[j]){
                j--;
                a[i]-=a[j];
            }
            else{
                i++;
                j--;
            }
        }else{//be the different
            if(a[i]<a[j]){
                i++;
                a[j]-=a[i];
                ans+=a[i];
            }
            else if(a[i]>a[j]){
                j--;
                a[i]-=a[j];
                ans+=a[j];
            }
            else{
                i++;
                j--;
                ans+=a[i];
            }
        }
    }
    cout<<ans;
    return 0;
}
