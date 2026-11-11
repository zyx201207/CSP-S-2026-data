#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long c,amax=0,anow;
    cin>>n>>m;
    vector<long long> a;
    for(int i=0;i<n;i++){
        cin>>c;
        a.push_back(c);
    }
    if(m==3){
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                for(int x=j+1;x<a.size();x++){
                    anow=a[i]&a[j]&a[x];
                    if(anow>amax) amax=anow;
                }
            }
        }
    }
    if(m==2){
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                anow=a[i]&a[j];
                if(anow>amax) amax=anow;
            }
        }
    }
    if(m==1){
        for(int i=0;i<a.size();i++){
            if(a[i]>amax) amax=a[i];
        }
    }
    if(m==n){
        amax=a[0];
        for(int i=1;i<a.size();i++){
            amax=amax&a[i];
        }
    }
    if(m==n-1){
        for(int i=0;i<a.size();i++){
            if(i==0) anow=a[1];
            else anow=a[0];
            for(int j=0;j<a.size();j++){
                if(j!=i) anow=anow&a[j];
            }
            if(anow>amax) amax=anow;
        }
    }
    cout<<amax;
    return 0;
}
