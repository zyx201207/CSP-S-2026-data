#include<bits/stdc++.h>
using namespace std;
long long n,a[1000001],sum,ans;
string cc[1000001],c[1000001],c1[1000001],c2[1000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int z=0;
    for(int i=0;i<n;i++){
        cin>>a[i]>>cc[i];
        ans+=a[i];
        for(int j=0;j<a[i];j++){
            c[z]=cc[i];
            z+=a[i];
            }
        }

    int j=0;
    int m=ans/2;
    if(ans%2==0){
        for(int i=0;i<m;i++){
            c1[i]==c[i];
        }
        for(int i=n-1;i>m;i--){
            c2[j]==c[i];
            j++;
        }
        for(int i=0;i<m-1;i++){
            if(c1[i]!=c2[i]) sum++;
        }
    }
    else{
        for(int i=0;i<m;i++){
            c1[i]==c[i];
        }
        for(int i=n-1;i>m+1;i--){
            c2[j]==c[i];
            j++;
        }
        for(int i=0;i<m-1;i++){
            if(c1[i]==c2[i]) sum++;
        }
    }
    cout<<sum;
    return 0;
}
