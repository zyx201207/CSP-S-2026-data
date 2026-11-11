#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.cpp","r",stdin);
    freopen("string.cpp","w",stdout);
    long long n,sum=0,wth=1;
    cin>>n;
    char c[2000010];
    for(int i=1;i<=n;i++){
        long long a;char o;
        cin>>a>>o;
        for(int j=1;j<=a;j++){
            c[wth]=o;
            wth++;
        }
    }wth--;
    if(wth%2==1){
        for(int i=(wth-1)/2;i>=1;i--){
            for(int j=wth/2+2;j<=wth;j++){
                if(c[i]!=c[j]) sum++;
            }
        }sum=sum/(wth-1)*2;
    }
    else{
        for(int i=wth/2;i>=1;i--){
            for(int j=wth/2+1;j<=wth;j++){
                if(c[i]!=c[j]) sum++;
            }
        }sum=sum/2;
    }cout<<sum;
    return 0;
}
