#include<bits/stdc++.h>
using namespace std;

vector<long long> a;
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    long long n=0,m=0;
    cin>>n>>m;
    long long x[200005]={};
    for(int i=0;i<n;i++){
        long long t=0;
        cin>>t;

        for(int j=0;j<i;j++){
            if(a[j]==t){
                for(int z=j;z<i;z++){
                    a.pop_back();
                }
            }
        }
        a.push_back(t);
        for(int j=0;j<i;j++){
            int f=a[j];
            x[f]++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<x[i]<<" ";
    }
    return 0;
}
