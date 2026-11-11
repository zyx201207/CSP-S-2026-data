#include <bits/stdc++.h>
using namespace std;

bool flag=1;
int n,m;
vector<long long> v;
int ans=0;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long a;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    if(v[0]==v[n-1]){
        cout<<n;
    }else{
        int ans_=1;
        int m2=m;
        for(int i=n-1;i>=0;i--){

            if(ans>=i+1) break;
            int j=i-1,t=v[i];
            while(m2>=0&&j>=0){
                if(m2>=t-v[j]){
                    ans_+=1;
                    m2-=t-v[j];
                }else{
                    m2-=t-v[i];
                    ans=max(ans,ans_);
                    break;
                }
                j--;

            }
            if(j<0){
                    cout<<n;
                    flag=0;
                    break;
                }
        }
        if(flag==1){
            cout<<ans;
        }
    }
    return 0;
}
