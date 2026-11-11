#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    pair<long long,char> a[200005];
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }
    long long sum=0;
    long long l=1,r=n;
    while(l<r){
        if(a[l].second!=a[r].second){
            if(a[l].first<a[r].first){
                sum+=a[l].first;
                a[r].first-=a[l].first;
                l++;
            }else if(a[l].first>a[r].first){
                sum+=a[r].first;
                a[l].first-=a[r].first;
                r--;
            }else{
                sum+=a[r].first;
                l++;
                r--;
            }
        }else{
            if(a[l].first<a[r].first){
                a[r].first-=a[l].first;
                l++;
            }else if(a[l].first>a[r].first){
                a[l].first-=a[r].first;
                r--;
            }else{
                r--;
                l++;
            }
        }
    }
    cout<<sum<<'\n';
    return 0;
}
