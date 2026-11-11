#include<bits/stdc++.h>
using namespace std;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string s;
    cin>>n;
    long long sum=0;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        a[i]=sum+1;
        int m;
        cin>>m;
        cin>>c[i];
        sum+=m;
    }
    a[n+1]=sum;
    int k=2;
    long long cnt=0;
    if(sum%2==1){
        for(int i=1;i<=(sum-1)/2;i++){
            //sum-i+1
            if(a[k]>=i){
                if(c[k-1]!=c[n-k+2]){
                    cnt++;
                }
            }else{
                k++;
                if(c[k-1]!=c[n-k+2]){
                    cnt++;
                }
            }
        }
    }else{
        for(int i=1;i<=sum/2;i++){
            //sum-i+1
            if(a[k]>=i){
                if(c[k-1]!=c[n-k+2]){
                    cnt++;
                }
            }else{
                k++;
                if(c[k-1]!=c[n-k+2]){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
