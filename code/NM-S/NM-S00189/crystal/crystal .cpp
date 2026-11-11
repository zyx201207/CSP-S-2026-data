#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,all_,cnt=0;
unsigned long long a[5000003],b[5000003];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        all_+=a[i];
    }
    sort(a+1,a+n+1);
    all_=ceil(all_/n);
    for(int i=1;i<=n;i++){
        if(all_<a[i]){
            all_=a[i+1];
        }
    }
    int k=1;
    for(int i=1;i<=n;i++){
        b[i]=all_-a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        if(m-b[i]>=0){
            cnt++;
            m-=b[i];
        }
        else{
            break;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
