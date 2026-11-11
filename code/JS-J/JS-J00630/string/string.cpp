#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll a1[200010],a2[200010],s1[200010],s2[200010];
char c1[200010],c2[200010];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);freopen("string.out","w",stdout);//read,write
    //don`t forget!!!!
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a1[i];
        cin>>c1[i];
        a2[n-i+1]=a1[i];
        c2[n-i+1]=c1[i];
    }
    for(int i=1;i<=n;i++){
        s1[i]=s1[i-1]+a1[i];
        s2[i]=s2[i-1]+a2[i];

    }
    //cout<<endl;
    ll mid=(s1[n]>>1);
    if(s1[n]&1)mid++;
   
    int l=1,r=1;//two pointers
    ll ans=0;
    while(s1[l]<mid&&s2[r]<mid){
        //cout<<l<<" "<<r<<endl;
        if(a1[l]>a2[r]){
            if(c1[l]!=c2[r])ans+=a2[r];
            a1[l]-=a2[r];
            r++;
        }
        else if(a1[l]==a2[r]){
            if(c1[l]!=c2[r])ans+=a1[l];
            a1[l]=a2[r]=0;
            l++;r++;
        }
        else{//<
            if(c1[l]!=c2[r])ans+=a1[l];
            a2[r]-=a1[l];
            l++;
        }
    }
    if(s1[l]>=mid){
        while(s2[r-1]<=mid){
            if(c1[l]!=c2[r])ans+=min(a2[r],mid-s2[r-1]);
            r++;
        }
    }
    else if(s2[r]>=mid){
        while(s1[l-1]<=mid){
            if(c1[l]!=c2[r])ans+=min(a1[l],mid-s1[l-1]);
            l++;
        }
    }
    cout<<ans;
    return 0;
}