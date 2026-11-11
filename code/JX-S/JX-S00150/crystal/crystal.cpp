#include<bits/stdc++.h>
using namespace std;
long long int n,m,zhong,sum=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>m>>n;
    int a[m],len[m];
    for(int i=0;i<m;i++) cin>>a[i];
    sort(a,a+m);
    zhong=a[m/2];
    for(int i=0;i<m/2;i++) len[i]=zhong-a[i];
    for(int i=m/2+1;i<m;i++) len[i]=a[i]-zhong;
    sort(len,len+m);
    int l=0;
    if(n<len[l]) cout<<1;
    else while(1){
        n-=len[l];
        if(n<0){
            break;
        }
        sum+=1;
        l++;
    }
    cout<<sum;
    return 0;
}
