#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
    int num;
    char op;
}a[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].op;
    }
    int biao1=1,biao2=n,num1=a[1].num,num2=a[n].num;
    char op1=a[1].op,op2=a[n].op;
    int ans=0;
    while(biao1<biao2){
        if(op1!=op2) ans+=min(num1,num2);
        if(num1<num2){
            ++biao1;
            num2-=num1;
            num1=a[biao1].num;
            op1=a[biao1].op;
        }
        else if(num1==num2){
            ++biao1,--biao2;
            num1=a[biao1].num,op1=a[biao1].op;
            num2=a[biao2].num,op2=a[biao2].op;
        }
        else{
            --biao2;
            num1-=num2;
            num2=a[biao2].num;
            op2=a[biao2].op;
        }
    }
    cout<<ans;
    return 0;
}
