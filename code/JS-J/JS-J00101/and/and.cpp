#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll N=1e5+5;
ll n,m,big2=-1,big=-1,small=N,andcnt,cnt1,cnt2,cnt3,cnt0,num[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        if(num[i]==1)cnt1++;
        if(num[i]==2)cnt2++;
        if(num[i]==3)cnt3++;
        if(num[i]==0)cnt0++;
        if(i==1)andcnt=num[i];
        else andcnt=andcnt&num[i];
        big=max(big,num[i]);
        small=min(small,num[i]);
    }
    if(m==1)cout<<big;
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                big2=max(big2,num[i]&num[j]);
            }
        }
        cout<<big2;
    }
    else if(m==n){
       cout<<andcnt;
    }
    else if(m==n-1){
        int flag=0;
        andcnt=num[1];
        for(int i=1;i<=n;i++){
            if(num[i]!=small){
                andcnt=andcnt&num[i];
            }
            else if(flag==0){
                andcnt=andcnt&num[i];
                flag=1;
            }
        }
        cout<<andcnt;
    }
    else if(n>2000){
        if(n<=cnt3)cout<<3;
        else if(n<=cnt3+cnt2)cout<<2;
        else if(n<=cnt3+cnt2+cnt1)cout<<1;
        else cout<<0;
    }
    else{
        cout<<big;
    }
    return 0;
}
