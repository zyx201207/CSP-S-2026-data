#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    vector< vector<bool> > a;
    vector<long long> b;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    a.resize(n,vector<bool>(32,0));
    int maxj=0;
    for(int i=0;i<n;i++){
        long long tmp;
        cin>>tmp;
        b.push_back(tmp);
        int j;
        for(j=0;tmp;j++){
            a[i][j]=tmp&1;
            tmp=(tmp>>1);
        }
        maxj=max(maxj,j);
    }
    for(int i=maxj-1;i>=0;i--){
        int s=0;
        for(int j=0;j<a.size();j++){
            if(a[j][i]) s++;
        }
        if(s>=m){
            for(int j=0;j<a.size();j++){
                if(!a[j][i]){
                    a.erase(a.begin()+j);
                    b.erase(b.begin()+j);
                }
            }
        }
    }
    sort(b.begin(),b.begin()+b.size(),cmp);
    long long ans=b[0];
    for(int i=1;i<m;i++){
        ans&=b[i];
    }
    cout<<ans;
    return 0;
}
