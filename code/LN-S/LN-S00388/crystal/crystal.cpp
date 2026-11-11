#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;    
    long long m,a[500010];
    cin>>n>>m;
    if(m==0){
        cout<<1<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int mx=0,j=0,last=0;
    long long sum=0;
    for(int i=0;i<n-1;i++){
        // cout<<"i="<<i<<endl;
        for(j=last+1;j<n;j++){
            // cout<<"  j="<<j<<endl;
            // cout<<"  sum:"<<sum<<"->";
            sum += (a[j]-a[j-1])*(j-i);
            // cout<<sum<<endl;
            if(sum>m){
                last=j-1;
                // cout<<"    last="<<last<<endl;
                sum -= (a[j]-a[j-1])*(j-i);
                sum -= (a[j-1]-a[i]);
                // cout<<"    sum="<<sum<<endl;
                break;
            }
        }
        mx = max(mx,j-i);
    }
    cout<<mx<<endl;
    return 0;
}
