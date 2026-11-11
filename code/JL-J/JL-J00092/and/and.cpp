#include<iostream>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,max2=0;
    cin>>n>>m;
    int a[n],b[n],max1[m+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[n]==a[n];
    }
    for(int j=0;j<n;j++){
         for(int i=0;i<n;i++){
            if(max2<a[i]){
                max2=a[i];
                a[i]=0;
            }
        }
        max1[j]=max2;
        max2=0;
    }
    cout<<max1[m-1];
    return 0;
}
