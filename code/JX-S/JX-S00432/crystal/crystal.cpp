#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
long long m;
long long a[100000000];
int dg(int b){
    int mid=b;
    int num=0;
    int sum=m;
    for(int i=0;i<=n;i++){
        if(sum>=(a[mid]-a[mid-i])){
            sum=sum-(a[mid]-a[mid-i]);
            if(mid-i>=0){
                num++;
            }
        }else{
            ans=max(num,ans);
            dg(b-1);
        }

    }
    return ans;


}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        if(a[i]>a[i+1]){
            swap(a[i],a[i+1]);
        }
    }
    cout<<dg(n);


    return 0;
}
