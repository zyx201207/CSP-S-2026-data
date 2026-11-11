#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    vector<pair<long long,char> > a,A;
    for (int i=0;i<n;i++){
        long long b;
        char c;
        cin>>b>>c;
        a.push_back(make_pair(b,c));
        A.push_back(make_pair(b,c));
    }
    reverse(A.begin(),A.end());
    long long ans=0;
    for (int i=0,j=0;i<n || j<n;){
        if (A[i].first>a[j].first){
            if (A[i].second!=a[j].second){
                ans+=a[j].first;
            }
            A[i].first-=a[j].first;
            j++;
        }
        else if (A[i].first<a[j].first){
            if (A[i].second!=a[j].second){
                ans+=A[i].first;
            }
            a[j].first-=A[i].first;
            i++;
        }
        else{
            if (A[i].second!=a[j].second){
                ans+=a[j].first;
            }
            i++;
            j++;
        }
    }
    cout<<ans/2;
    return 0;
}
