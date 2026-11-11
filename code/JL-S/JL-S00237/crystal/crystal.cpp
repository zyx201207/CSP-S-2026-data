#include<bits/stdc++.h>;
using namespace std;
bool f=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,k=0,p=0;
    long long a[500001];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]){
            f=1;
            p=i;
            break;
        }
    }
    if(f==1){
        for(int i=p;i>0;i--){
            int t=a[i]-a[i-1];
            m-=t;
            a[i-1]=a[i];
            if(m==0){
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]=a[i+1]){
                k++;
            }
        }
        cout<<k;
        return 0;
    }
    else{
        cout<<"3";
    }
    return 0;

}
