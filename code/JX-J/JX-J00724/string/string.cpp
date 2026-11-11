#include<bits/stdc++.h>
using namespace std;
long long a[200003];
char b[200003];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    int l=1,r=n;
    long long c=0;
    while(l<r){
        if(b[l]!=b[r]){
            if(a[l]>a[r]){
                c+=a[r];
                a[l]-=a[r];
                r--;
            }else if(a[l]<a[r]){
                c+=a[l];
                a[r]-=a[l];
                l++;
            }else{
                c+=a[r];
                l++;
                r--;
            }
        }else{
            if(a[l]==a[r]){
                l++;
                r--;
            }else if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }else{
                a[l]-=a[r];
                r--;
            }
        }
    }cout<<c;
    return 0;

}
