#include<bits/stdc++.h>
using namespace std;
struct node{
    int num;
    char c;
}a[200005];
int cmp(node d[200005],int x,int y){
    if(d[x].num > d[y].num) return x;
    else return y;
}
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].c;
    }
    long long sum=0;
    int n2=0,i2=0;
    if(n%2 == 0){
        n2=n/2;
        i2=1;
    }
    else{
        n2=n/2+1;
        i2=0;
    }
    for(int i=1;i<=n2;i++){
        if(a[i].c != a[n-i+i2].c){
            sum+=min(a[i].num,a[n-i+i2].num);
            a[cmp(a,i,n-i+i2)].num=abs(a[i].num-a[n-i+i2].num);
        }
    }
    cout<<sum;
    return 0;
}
