#include <bits/stdc++.h>
using namespace std;
long long n,ans;
pair <long long , char> p;
vector <pair<long long ,char> > v;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i =1;i<=n;i++){
        int m;
        char c;
        cin>>m>>c;
        p = {m,c};
        v.push_back(p);
    }
    long long l = 0,r = n-1;
    while(l<r){

        if(v[l].first > v[r].first){
            v[l].first -= v[r].first;
            if(v[l].second != v[r].second) ans +=v[r].first;
            r--;
        }else if(v[l].first < v[r].first){
            v[r].first -= v[l].first;
            if(v[l].second != v[r].second) ans +=v[l].first;
            l++;
        }else{
            if(v[l].second != v[r].second) ans +=v[r].first;
            l++;r--;
        }
    }


    cout<<ans;

    return 0;
}

