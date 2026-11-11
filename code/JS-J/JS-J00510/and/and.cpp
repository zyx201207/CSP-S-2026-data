#include<bits/stdc++.h>
using namespace std;
long long a[300005];
vector<long>v;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=31;i>=0;i--){
        long long b=pow(2,i),s=0;
        for(int j=1;j<=n;j++){
            if(a[j]/b%2==1){
                s++;
                v.push_back(a[j]);
            }
        }
        if(s>=m){
            break;
        }
        else{
            v.clear();
        }
    }
    if(v.empty()){
        cout<<0;
        return 0;
    }
    else{
        for(int i=31;i>=0;i--){
            long long b=pow(2,i),s=0;
            for(int j=0;j<v.size();j++){
                if(v[j]/b%2==1)s++;
            }
            if(s>=m){
                for(int j=0;j<v.size();j++){
                    if(v[j]/b%2==0)v.erase(v.begin()+j);
                }
            }
        }
    }
    sort(v.begin(),v.end(),greater<long>());
    int s=v[0];
    for(int i=1;i<m;i++){
        s=s&v[i];
    }
    cout<<s;
    return 0;
}
