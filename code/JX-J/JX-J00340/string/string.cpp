#include<bits/stdc++.h>
using namespace std;
struct node{
    long long num;
    char a;
}s1[200005];
long long n,cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s1[i].num>>s1[i].a;
    for(int i=1,j=n;i<=j;i+=0){
        long long z=min(s1[i].num,s1[j].num);
        if(s1[i].a!=s1[j].a) cnt+=z;
        s1[i].num-=z,s1[j].num-=z;
        if(!s1[i].num) i++;
        else j--;
    }
    cout<<cnt;
    return 0;
}
