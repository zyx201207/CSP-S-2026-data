

#include<bits/stdc++.h>
using namespace std;
class A{
public:
    long long num;
    char c;
};
A aa[200005];
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    /*
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    */
    int n,count_;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>aa[i].num;
        cin>>aa[i].c;
    }

    unsigned long long ans=0;
    int p=0,q=n-1;
    while(p<q){
        count_=min(aa[p].num,aa[q].num);
        if(aa[p].c!=aa[q].c) ans+=count_;
        aa[p].num-=count_;
        aa[q].num-=count_;
        if(aa[p].num==0) p++;
        if(aa[q].num==0) q--;

    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

