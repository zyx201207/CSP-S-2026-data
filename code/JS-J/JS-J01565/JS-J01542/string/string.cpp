#include <bits/stdc++.h>
using namespace std;
long long a[1000001];
char c[1000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,s=0,y=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<=r){
        cout<<a[l]<<" "<<a[r]<<endl;
        if(c[l]==c[r]){
            if(a[l]>a[r]){
                a[l]=a[l]-a[r];
                r--;
            }else if(a[l]<a[r]){
                a[r]=a[r]-a[l];
                l++;
            }else{
                r--;
                l++;
            }
        }else{
            if(a[l]>a[r]){
                s+=a[r];
                a[l]=a[l]-a[r];
                r--;
            }else if(a[l]<a[r]){
                s+=a[l];
                a[r]=a[r]-a[l];
                l++;
            }else{
                s+=a[l];
                r--;
                l++;
            }
        }
    }
    cout<<s;
    return 0;
}
//9 2 a 1 d 1 b 1 g 1 f 1 k 3 x 4 i 1 s
