#include<bits/stdc++.h>
using namespace std;
int a[200010],n;
long long z=0,ans=0;
char b[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>b[i];
        z+=a[i];
    }
    if(z%2==1)z=z/2+1;
    else z=z/2;
    int w;
    long long l=0;
    for(int i=0;i<n;i++){
        l+=a[i];
        if(l>=z){
            w=i;
            break;
        }
    }
    int i=0,j=n-1;
    while(i<=j){
        if(a[i]>a[j]){
            if(b[i]!=b[j]){
                ans+=a[j];
            }
            a[i]-=a[j];
            j--;
        }
        else if(a[i]==a[j]){
            if(b[i]!=b[j]){
                ans+=a[j];
            }
            i++;
            j--;
        }
        else if(a[i]<a[j]){
            if(b[i]!=b[j]){
                ans+=a[i];
            }
            a[j]-=a[i];
            i++;
        }
    }
    cout<<ans;
    return 0;
}
