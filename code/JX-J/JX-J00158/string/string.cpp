#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010],h[200010],l,r,sum;
char c[200020];
string s,s1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
    }
    long long ans=a[1],ap=a[n],x=n;
    for(int i=1,j=n;i<j;){
        if(ans>ap){
            if(c[i]!=c[j]){
                sum+=ap;
            }
            ans=ans-ap;
            j--;
            ap=a[j];
        }
        if(ans<ap){
            if(c[i]!=c[j]){
                sum+=ans;
            }
            ap=ap-ans;
            i++;
            ans=a[i];
        }
        if(ans==ap){
            if(c[i]!=c[j]){
                sum+=ans;
            }
            i++;
            j--;
            ans=a[i];
            ap=a[j];
        }
    }
    cout<<sum;
    return 0;
}
