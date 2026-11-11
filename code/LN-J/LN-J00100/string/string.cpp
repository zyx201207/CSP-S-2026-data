#include<bits/stdc++.h>
using namespace std;
long long ans;
const int N=2e5+10;
struct node{
    char c;
    int num;
}a[N];
int n;
int main (){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].c;
    }
    for(int l=1,r=n;l<=r;){
        if(a[l].c==a[r].c){
            if(a[l].num>a[r].num){
                a[l].num-=a[r].num;
                r--;
            }else if(a[l].num<a[r].num){
                a[r].num-=a[l].num;
                l++;
            }else{
                r--,l++;
            }
        }else{
            if(a[l].num>a[r].num){
                a[l].num-=a[r].num;
                ans+=a[r].num;
                r--;
            }else if(a[l].num<a[r].num){
                ans+=a[l].num;
                a[r].num-=a[l].num;
                l++;
            }else{
                ans+=a[l].num;
                r--,l++;
            }
        }
    }
    cout<<ans;

    return 0;
}
