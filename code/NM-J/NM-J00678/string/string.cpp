#include<bits/stdc++.h>
using namespace std;
int n,x,cnt;
long long ans;
char c;
pair<int,char> a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        a[++cnt]={x,c};
    }
    int i=1,j=cnt;
    while(i<j){
        if(a[i].second!=a[j].second){
            ans+=min(a[i].first,a[j].first);
            if(a[i].first>a[j].first){
                a[i].first-=a[j].first;
                a[j].first=0;
                j--;
            }else if(a[i].first==a[j].first){
                a[i].first=0;
                a[j].first=0;
                i++,j--;
            }else{
                a[j].first-=a[i].first;
                a[i].first=0;
                i++;
            }

        }
        else{
            if(a[i].first>a[j].first){
                a[i].first-=a[j].first;
                a[j].first=0;
                j--;
            }else if(a[i].first==a[j].first){
                a[i].first=0;
                a[j].first=0;
                i++,j--;
            }else{
                a[j].first-=a[i].first;
                a[i].first=0;
                i++;
            }
        }
    }
    cout<<ans;
    return 0;
}
