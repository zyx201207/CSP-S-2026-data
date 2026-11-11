#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],ans;
char c[1000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //freopen("string6.in","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=0,j=n-1;i<j;){
        //cout<<"i="<<i<<" j="<<j<<endl;
        if(c[i]==c[j]){//如果一样，消
            if(a[i]<a[j]){
                a[j]-=a[i];
                i++;
                //continue;
            }else if(a[i]>a[j]){
                a[i]-=a[j];
                j--;
            }else{
                i++;j--;
            }
        }
        else{
            ans+=min(a[i],a[j]);
            if(a[i]<a[j]){
                a[j]-=a[i];
                i++;
            }else if(a[i]>a[j]){
                a[i]-=a[j];
                j--;
            }else{
                i++;j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
