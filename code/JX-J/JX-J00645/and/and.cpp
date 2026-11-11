#include<bits/stdc++.h>
using namespace std;
const long long N=200009;
long long n,m,sum;
struct node{long long zero,one,val;};
bool cmp(node a,node b){
    if(a.one!=b.one)return a.one>b.one;
    return a.zero>b.zero;
}
node arr[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x=0;
        cin>>x;
        arr[i].val=x;
        while(x){
            if(x%2==1){
                arr[i].one++;
            }
            else{arr[i].zero++;}
            x/=2;
        }
    }
    sort(arr+1,arr+n+1,cmp);
    sum=arr[1].val;
    int k=0;
    for(int i=2;i<=m+k;i++){
        if(sum<arr[i].val){
            i++;
            k++;
        }
        sum=sum&arr[i].val;
    }
    cout<<sum;
    return 0;
}
