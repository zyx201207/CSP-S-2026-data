#include<bits/stdc++.h>
using namespace std;
vector<int> jj;
int findk(int n,int k){
    while(n){
        n/=2;
        k++;
    }
    return k;
}
bool findj(int tar){
    for(int i=jj.size()-1;i>=0;i--){
        if(jj[i]==tar){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n,m;
    long long t,ans=0;
    vector<long long> a;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>t;
        a.push_back(t);
    }
    sort(a.begin(),a.end());
    if(m==1){
        cout<<a[n-1];
        return 0;
    }
    if(m==n){
        cout<<a[0];
        return 0;
    }
    int k=0,ci[50],que=0;
    k=findk(a[n-1],k);
    for(int i=k-1;i>=0;i--){
        int te=0,firs=jj.size();
        for(int j=n-1;j>=0;j--){
            if(que&&!findj(j)){
                continue;
            }
            if((a[j]>>i)&1){
                te++;
                jj.push_back(j);
            }
        }
        if(te>=m){
            que=1;
            if(i==0){
                ans+=1;
            }
            ans+=(2<<(i-1));
        }
        if(!que){
            for(int q=firs;q>0;q--){
                jj.pop_back();
            }
        }
    }
    cout<<ans;
    return 0;
}
