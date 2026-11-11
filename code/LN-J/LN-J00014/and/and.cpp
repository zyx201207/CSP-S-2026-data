#include<iostream>
using namespace std;
long long num[200005];
long long s[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,max1=-1;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>num[i];
        if(num[i]>max1)max1=num[i];
    }
    if(m==2){
        max1=-1;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(num[i]&num[j]>max1){
                    max1=num[i]&num[j];
                }
            }
        }
    }
    if(m==n){
        max1=num[0];
        for(int i=1;i<n;i++){
            max1=max1&num[i];
        }
    }
    if(m==n-1){
        max1=-1;
        for(int i=0;i<n;i++){
            if(i==0)long long max2=num[1];
            else long long max2=num[0];
            for(int j=1;j<n;j++){
                if(j==i) continue;
                max2=max2&num[j];
            }
            if(max2>max1)max1=max2;
        }
    }
    cout<<max1<<endl;

    return 0;
}
