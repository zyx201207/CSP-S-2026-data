#include<bits/stdc++.h>
using namespace std;
long long a[20005];
char s[20005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cin>>s[i];
    }
    long long ans=0;
    for(int i=1,j=n;i<=n&&j>=1&&i<j;){
        if(s[i]!=s[j]){
            if(a[i]>a[j]){
                a[i]-=a[j];
                ans+=a[j];
                j--;
            }else if(a[j]>a[i]){
                a[j]-=a[i];
                ans+=a[i];
                i++;
            }else{
                ans+=a[i];
                i++;
                j--;
            }
        }else{
             if(a[i]>a[j]){
                a[i]-=a[j];
                j--;
            }else if(a[j]>a[i]){
                a[j]-=a[i];
                i++;
            }else{
                i++;
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
