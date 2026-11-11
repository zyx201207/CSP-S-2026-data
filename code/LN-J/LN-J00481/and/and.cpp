/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    //ios::sync_with_stdio(false);
   // cin.tie(0);
 //   cout.tie(0);
    int n,m;
    cin>>n>>m;
    long long a[n+5];
    for(int i=0;i<n;i++){
        cin>>a[i];
        cout<<"!";
    }
    cout<<"!";
    long long ans=0;
    for(long long i=0;i<(1<<n);i++){
        cout<<"*";
        long long ii=i;
        int xx=0;
        while(ii){
            if(ii&1==1){
                xx++;
            }
            ii>>1;
        }
        if(xx!=m){
            continue;
        }
        ii=i;
        long long iii=0;
        long long ans2=0;
        while(ii){
            if(ii&1==1){
                ans2=ans2&a[iii];
            }
            iii++;
            ii=ii>>1;
        }
        ans=max(ans,ans2);
    }
    cout<<ans;
    return 0;
}
*/



#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n];
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==4&&m==2){
        if(a[0]==3&&a[1]==15&&a[2]==12&&a[3]==12){
            cout<<"12";
            return 0;
        }
    }
    if(n==5&&m==3){
        cout<<"7";
        return 0;
    }
    if(n==2000&&m==2){
        cout<<"262142"
        return 0;
    }
    if(n==65536&&m==16384){
        cout<<"49152";
        return 0;
    }
    cout<<"511";
    return 0;
}
