#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
pair<int,char> p[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i].first>>p[i].second;
    for(int i=0,j=n-i-1;i<n/2&&i<=j;){
        if(p[i].second!=p[j].second){
            if(p[i].first==p[j].first&&p[i].second!=p[j].second){
                ans+=p[i].first;
                i++;
                j--;
                continue;
            }
            while(p[i].first>p[j].first){
                if(p[i].second!=p[j].second){
                    ans=ans+p[j].first;
                }
                p[i].first-=p[j].first;
                j--;
            }
            while(p[i].first<p[j].first){
                if(p[i].second!=p[j].second){
                    ans=ans+p[i].first;
                }
                p[j].first-=p[i].first;
                i++;
            }
        }
        else{
            if(p[i].first==p[j].first&&p[i].second==p[j].second){
                i++;
                j--;
                continue;
            }
            while(p[i].first>p[j].first){
                p[i].first-=p[j].first;
                j--;
            }
            while(p[i].first<p[j].first){
                p[j].first-=p[i].first;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
