#include<bits/stdc++.h>
#define ll long long

using namespace std;
long long n,m;
long long cr[600003];
long long cha[600002],sum[600002],cha2[600002];
long long cnt=1,l=1,cnt2=0;
long long maxn=-1;
long long tot=0,tot1=0;
long long ds=0;
long long pas=0;
//I dont know what will happen
//bAd Day
//eps
//math
//physics
//chinese
//english
//guessss
//fa shao
//daleliangtainzhen,ganjuehenhun,,,,NOIP i can
int main()
{
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
cin>>n>>m;
for(ll i=1;i<=n;i++){

    cin>>cr[i];

}
sort(cr+1,cr+1+n);
for(ll i=1;i<n;i++){
    cha[i]=cr[i+1]-cr[i];
    cha2[i]=cha2[i-1]+i*cha[i];
}
if(n<=5000){
    for(ll i=1;i<n;i++){
            ll pas=i+1;
    if(cha2[i]<=m){
    maxn=max(pas,maxn);
    }else{

        for(ll j=l;j<=i;j++){
        if(cha2[i]-(cr[i+1]-cr[j])<=m){
            cha2[i]=cha2[i]-(cr[i+1]-cr[j]);
            pas--;
            maxn=max(maxn,pas);
            l=j+1;
         continue;
        }else{
        pas--;
        cha2[i]=cha2[i]-(cr[i+1]-cr[j]);

        }
        }

    }
    }
    cout<<maxn;
}else{

for(ll i=1;i<n;i++){

    if(cha2[i]<=m){
        cnt++;
        maxn=max(cnt,maxn);
    cha2[i+1]=cha2[i+1]-tot-(cnt2*(cr[i+2]-cr[ds]));
      //  cout<<"Win "<<i<<"\n";
    }else{
        tot1=0;
for(ll j=l;j<i+1;j++){
    if(cha2[i]-tot1-(cr[i+1]-cr[j])<=m){
      //  sum[i]=sum[i]-sum[i-1];
      tot1+=cr[i+1]-cr[j];
      cnt2++;
        cha2[i]=cha2[i]-tot1;
        ds=j+1;
        l=j+1;

        cnt--;
        //maxn=max(maxn,cnt);
        continue;
    }else{
    tot1=tot1+cr[i+1]-cr[j];
    cnt--;
    cnt2++;
    }
}
tot+=tot1;
cha2[i+1]=cha2[i+1]-tot-(cnt2*(cr[i+2]-cr[ds]));

    }

}
cout<<maxn;

}
 return 0;
}
