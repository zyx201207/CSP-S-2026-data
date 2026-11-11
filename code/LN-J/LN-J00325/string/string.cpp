#include<bits/stdc++.h>
using namespace std;
struct node{
    long long num;
    char c;
}ne[200001];
long long n,ans=0;
long long l,r;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    long long k;
    char k2;
    for(long long i=1;i<=n;i++){
        cin>>ne[i].num>>ne[i].c;
        //scanf("%lld%c",&k,&ne[i].c);
       // ne[i].num=k;
    }
    l=1;r=n;
    ans=0;
    while(l<r){
       // prlong longf("%lld %lld %lld\n",l,r,ans);
        if(ne[l].c!=ne[r].c){
           //prlong longf("aa %lld %lld %lld %lld %lld\n",l,r,ans,ne[l].num,ne[r].num);
            if(ne[l].num>ne[r].num){
                ans+=ne[r].num;
                //prlong longf("al1 %lld\n",ne[r].num);
                ne[l].num-=ne[r].num;
                r--;
                continue;
            }
            else if(ne[l].num<ne[r].num){
                ans+=ne[l].num;
                //prlong longf("al2 %lld\n",ne[r].num);
                ne[r].num-=ne[l].num;
                l++;
                continue;
            }
            else{// if(ne[l].num==ne[r].num)
                ans+=ne[r].num;
                //prlong longf("al3 %lld\n",ne[r].num);
                l++;
                r--;
                continue;
            }
        }
        if(ne[l].c==ne[r].c){
            if(ne[l].num>ne[r].num){
                ne[l].num-=ne[r].num;
                r--;
                continue;
            }
            else if(ne[l].num<ne[r].num){
                ne[r].num-=ne[l].num;
                l++;
                continue;
            }
            else{//if(ne[l].num==ne[r].num)
                l++;
                r--;
                continue;
            }
        }
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
