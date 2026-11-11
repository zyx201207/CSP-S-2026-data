#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    cin>>a;
    char cn[200005];
    int n[200005];
    int all=0;
    int kn=0,cou1=0,cou2=0;
    char co=' ';
    for(int i=1;i<=a;i++){
        int k;
        char c;
        cin>>k>>c;
        if(c==co){
            kn+=k;
            continue;
        }
        if(i==1){
            kn=k;
            co=c;
            continue;
        }
        all+=kn;
        n[++cou1]=kn;
        cn[++cou2]=co;
        kn=k;
        co=c;
    }
    all+=kn;
    n[++cou1]=kn;
    int count1=0;
    int left=0,right=all,l=1,r=cou2;
    while(left<=right && l<=r){
        int mid=min(n[l],n[r]);
        left+=mid;
        right-=mid;
        n[l]-=mid;
        if(cn[l]!=cn[r])count1+=mid;
        if(n[l]==0)l++;
        if(n[r]==0)r--;
    }
    cout<<count1;
    fclose(stdin);
    fclose(stdout);
    return 0;

}
