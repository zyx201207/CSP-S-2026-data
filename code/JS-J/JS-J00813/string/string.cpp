#include<bits/stdc++.h>
using namespace std;

long long a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }

    int i=1,j=n;
    long long ans=0;
    while(i<j){
        if(c[i]!=c[j]){
            if(a[i]>a[j]){
                ans+=a[i]-a[j];
                a[i]-=a[j];
                a[j]=0;
                j--;
            }
            else if(a[i]<a[j]){
                ans+=a[j]-a[i];
                a[j]-=a[i];
                a[i]=0;
                i++;
            }
            else{
                ans+=a[i];
                a[i]=0;
                a[j]=0;
                i++;
                j--;
            }
        }
        else{
            if(a[i]>a[j]){
                a[i]-=a[j];
                a[j]=0;
                j--;
            }
            else if(a[i]<a[j]){
                a[j]-=a[i];
                a[i]=0;
                i++;
            }
            else{
                a[i]=0;
                a[j]=0;
                i++;
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
