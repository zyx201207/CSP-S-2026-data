#include<bits/stdc++.h>
using namespace std;

long long n,m;
vector<long long> a;
map<long long ,long long>b;
long long ans=0;

void solve1(){

    for(auto i=b.begin();i!=b.end();i++){

        long long tans=i->second;
        if(i==b.begin())continue;
        long long m1=m;
        auto j=i;
        for(;;){
            if(m1<=0){
                break;
            }

            j--;
            long long need=i->first-j->first;
            long long num=j->second;
            long long can=m1/need;
            long long re_num;
            if(can>=num){
                re_num=num;
            }
            else{
                re_num=can;
            }
            m1-=re_num*need;
            tans+=re_num;

            if(j==b.begin()){
                break;
            }
        }
        if(tans>ans)ans=tans;

    }







}





int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        long long x;
        b[x]++;
        cin>>x;
        a.push_back(x);
    }
    solve1();
    cout<<ans;

    return 0;
}
