#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int&i:a)cin>>i;
    int cnt=0;
    vector<int>k=a;
    while(cnt<m){
        cnt++;
        vector<int>p=k;
        k.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<p.size();j++){
                if(a[i]==p[j])continue;
                k.push_back(a[i]&p[j]);
            }
        }
    }
    sort(k.begin(),k.end());
    cout<<k[k.size()-1]<<endl;
    return 0;
}