#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[2000005];
bool judge(int le,int ri,int kl,int kr){
    if (kl==kr){
        if (a[ri]-a[kl-1]<=d){
            if (a[kr+1]-a[le]<=d){
 //               cout<<le<<" "<<ri<<" "<<"3"<<"\n";
                return false;
            }else{
                if (a[ri]-a[kl-2]<=d){
   //                 cout<<le<<" "<<ri<<" "<<"4"<<"\n";
                    return false;
                }else{
    //                cout<<le<<" "<<ri<<" "<<"1"<<"\n";
                    return true;
                }
            }
        }else{
            int kkr=kr;
            while (a[kkr+1]-a[le]<=d){
                kkr++;
                if (kkr>n){
                    break;
                }
            }
            if (kkr-kr==1){
     //           cout<<le<<" "<<ri<<" "<<"2"<<"\n";
                return true;
            }else{
       //         cout<<le<<" "<<ri<<" "<<"5"<<"\n";
                return false;
            }
        }
    }else{
        if ((a[ri]-a[kl-1]>d)&&(a[kr+1]-a[le]>d)){
            return true;
        }else{
            return false;
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>t;
    for (int i=0;i<t;i++){
        long long ans=0;
        cin>>n>>d;
        for (int j=1;j<=n;j++){
            cin>>a[j];
        }
        int k=1;
        while (a[n]-a[k]>d){
            k++;
            if (k>n){
                break;
            }
        }
        int nk=k;
        while (a[nk]-a[1]<=d){
            nk++;
            if (nk>n){
                break;
            }
        }
        nk--;
        if (nk-k>1){
            cout<<0<<"\n";
            continue;
        }else{
            int l=1,r=n;
            while (l<k&&n>nk){
                if (judge(l,r,k,nk)){
                    ans++;
                }
                l++;
                if (judge(l,r,k,nk)){
                    ans++;
                }
                l--;
                r--;
                if (judge(l,r,k,nk)){
                    ans++;
                }
                l++;

            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
