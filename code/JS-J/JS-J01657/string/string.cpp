#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
pair<long long,char> a[N];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        cnt+=a[i].first;
    }
    long long ans=0;
    for(int i=1,j=n;i<=j;){
        if(i==j)break;
        if(a[i].first>a[j].first){
            if(a[i].second!=a[j].second)ans+=a[j].first;
            a[i].first-=a[j].first;
            a[j].first=0;
            j--;
        }else if(a[i].first<a[j].first){
            if(a[i].second!=a[j].second)ans+=a[i].first;
            a[j].first-=a[i].first;
            a[i].first=0;
            i++;
        }else{
            if(a[i].second!=a[j].second)ans+=a[i].first;
            a[j].first=0;
            a[i].first=0;
            i++;
            j--;
        }
    }
    cout<<ans;
    return 0;
}
