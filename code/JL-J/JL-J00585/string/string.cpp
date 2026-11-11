#include<bits/stdc++.h>
using namespace std;
struct NUM{
    char c;
    long long num;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i].num>>a[i].c;
    }
    long long maxx=0;
    long long l=1,r=n;
    while(l<r){
        if(a[l].c==a[r].c){
            long long minn=min(a[l].num,a[r].num);
            a[l].num-=minn;
            a[r].num-=minn;
        }
        else{
            maxx+=min(a[l].num,a[r].num);
            long long minn=min(a[l].num,a[r].num);
            a[l].num-=minn;
            a[r].num-=minn;
        }
        if(a[l].num==0) l++;
        if(a[r].num==0) r--;
        //cout<<maxx<<endl;
    }
    cout<<maxx<<endl;
    return 0;
}
