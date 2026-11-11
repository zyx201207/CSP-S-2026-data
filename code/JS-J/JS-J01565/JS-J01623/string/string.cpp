#include<iostream>
using namespace std;
int n;
long long ans;
char c[200005];
int a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1,j=n;i<j;){
        if(c[i]==c[j]){
            if(a[i]==a[j]){
                i++,j--;
            }else if(a[i]>a[j]){
                a[i]-=a[j];
                j--;
            }else{
                a[j]-=a[i];
                i++;
            }
        }else{
            if(a[i]==a[j]){
                ans+=a[i];
                i++,j--;
            }else if(a[i]>a[j]){
                ans+=a[j];
                a[i]-=a[j];
                j--;
            }else{
                ans+=a[i];
                a[j]-=a[i];
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
