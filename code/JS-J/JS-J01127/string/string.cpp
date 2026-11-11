#include <bits/stdc++.h>
using namespace std;
//#define debug
vector <pair<char,long long> > as;
int main(){
#ifndef debug
freopen("string.out","w",stdout);
freopen("string.in","r",stdin);
#endif
    int n;
    cin>>n;
    as.reserve(n);
    for(int _=0;_<n;_++){
        long long t;
        char tt;
        cin>>t>>tt;
        as.push_back(make_pair(tt,t));
    }
    long long ln=0,loff=0,rn=n-1,roff=as[n-1].second-1;
    long long ans=0;
    while(1){
       int offt=min(roff,as[ln].second-loff-1);
        if (ln>rn) {break;}
        if (ln==rn) {
            while(loff+offt>=roff-offt){
                offt--;
            }
            if(offt<=0) break;
        }
        if(offt<=-1) break;
        if(as[ln].first!=as[rn].first) {ans+=offt;}
        loff+=offt;
        roff-=offt;
        offt=1;
        if (ln>rn) {break;}
        if (ln==rn) {
            while(loff+offt>=roff-offt){
                offt--;
            }
            if(offt<=0) break;
        }
        loff++;
        roff--;
        if(as[ln].first!=as[rn].first) {ans++;}
        while(loff>=as[ln].second) {
            loff-=as[ln].second;
            ln++;
        }
        while(roff<0){
            rn--;
            roff+=as[rn].second;
}



        }
    cout<<ans;
#ifndef debug
fclose(stdout);
fclose(stdin);
#endif
    return 0;
    }
