#include<bits/stdc++.h>
using namespace std;
struct st{
    long long num;
    char w;
};
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n;
cin>>n;
st a[n+1];
for(long long i=1;i<=n;i++){
        cin>>a[i].num>>a[i].w;
}
long long l=1,r=n;
long long sum=0;
while(l<=r){
    if(l==r){
        break;
    }
    else{

        if(a[l].w==a[r].w){
            if(a[l].num>a[r].num){
                a[l].num-=a[r].num;
                r--;
            }
            else if(a[l].num==a[r].num){
                l++;
                r--;
            }
            else{
                a[r].num-=a[l].num;
                l++;
            }
        }
        else{
            sum+=1ll*min(a[l].num,a[r].num);
            if(a[l].num>a[r].num){
                a[l].num-=a[r].num;
                r--;
            }
            else if(a[l].num==a[r].num){
                l++;
                r--;
            }
            else{
                a[r].num-=a[l].num;
                l++;
            }
        }
    }
}
cout<<sum;
return 0;
}
