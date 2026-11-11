#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    bool pts=true;
    int cha=0;
    int a[100005]={0};
    int n,m;
    cin>>n>>m;
    int minn=1919810,maxn=-1145145;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        minn=min(minn,a[i]);
        maxn=min(maxn,a[i]);
        if(i==2){
            cha=abs(a[i]-a[i-1]);
        }
        if(i>2){
            if(abs(a[i]-a[i-1])==cha){
                pts=1;
            }
            else{
                pts=0;
            }
        }
    }
    int maxans=0;int ans=0;
    if(pts==false){
    sort(a+1,a+1+n);
    for(int i=minn;i<=maxn;i++){
        for(int j=1;j<=n;j++){
            ans=0;
            while(m){
                m=m-a[j]+i;
                ans+=1;
            }
            maxans=max(maxans,ans);
        }
    }
    cout<<maxans;
    }

    else{
        sort(a+1,a+1+n);
        int top=1;
        while(m){
            m-=(cha*top);
            top++;
        }
        cout<<top;
    }

    return 0;
}
