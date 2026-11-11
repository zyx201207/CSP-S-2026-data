#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll shi[500005]={0},eab[500005],rear=0,sum=-1,psub;
bool isab=true;
int solve(ll n,ll m){
    sort(shi,shi+n);
    for(ll i=0,count=1,lins=m;i<n;i++,count=1,lins=m){
        int j=i-1;
        while(j>=0){
            if(lins-(shi[i]-shi[j])>=0) count++,lins-=(shi[i]-shi[j]);
            j--;
        }
        
        if(sum<count) sum=count;
    }
    return sum;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;cin>>n>>m;
    for(int i=0,neab;i<n;i++){
        cin>>shi[i];
        if(i!=0) eab[rear++]=shi[i]-shi[i-1];
    } 
    //check is A and B?
    for(int i=1;i<rear;i++) if(eab[i]!=eab[i-1]) isab=false;
    
    if(isab){
        psub=shi[0];
        for(int i=0,a=psub;i<n&&m>=0;i++,sum++){
            m-=a,a+=psub;
        }
        cout<<sum;
    }
    else cout<<solve(n,m);
    return 0;
}