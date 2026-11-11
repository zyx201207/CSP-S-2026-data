#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
ll normal[500005]={};
ll ans=0;
//ll tong[1000001]={};


int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>normal[i];
        //tong[normal[i]]++;

    }
    sort(normal+1,normal+1+n);

    for(ll i=1;i<=normal[n];i++){
        ll p=0;/*zui da xia biao*/
        /*for(ll j=1;j<=n;j++){
            if(normal[j]>i){
                p=j-1;
                break;
            }

        }*/

        ll l=1,r=n,an1,ans1;
        while(1){

            an1=(l+r)/2;
            if(normal[an1]>i){
                r=an1-1;
            }
            else{
                l=an1+1;
                ans1=an1;
            }

            if(l>r){
                break;
            }



        }


        ll num=0;/*dang qian you duo shao ke shui jin can jia*/
        ll an=0;/*cao zuo ci shu*/
        ll p1=0;/*shi fou chao chu yao qiu*/
        p=ans1;

        for(ll j=1;j<=p;j++){
            num++;
            an+=i-normal[j];
            if(an>m){
                p1=1;
                break;
            }

        }
        if(p1==1){
            continue;
        }

        if(num>ans){
            ans=num;
        }



    }



    cout<<ans;


    return 0;
}
