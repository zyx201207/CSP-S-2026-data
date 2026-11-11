#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   // ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    vector <pair<int,char>> a;
    a.push_back({0,'a'});
    int l=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        char c;
        cin>>c;
        l+=x;
        a.push_back({x,c});
    }
    if(n==1){
        cout<<0<<endl;
        fclose(stdin);
    fclose(stdout);
        return 0;
    }
    int i=1,j=n;
    int li=a[1].first,lj=a[n].first;
    int ans=0;
    while(i!=j){
        if(li==lj){
            if(a[i].second==a[j].second);
            else if(lj-a[j].first>li-a[i].first) ans+=a[j].first;
            else ans+=a[i].first;
            j--,lj+=a[j].first;
            i++,li+=a[i].first;
        }
        else if(li>lj){
            if(a[i].second==a[j].second);
            else if(lj-a[j].first>li-a[i].first) ans+=a[j].first;
            else ans+=lj-(li-a[i].first);
            j--,lj+=a[j].first;
        }
        else{
            if(a[i].second==a[j].second);
            else if(lj-a[j].first<li-a[i].first) ans+=a[i].first;
            else ans+=li-(lj-a[j].first);
            i++,li+=a[i].first;
        }
       //cout<<ans<<endl;
    }
   // cout<<"fsda"<<endl;
    //cout<<ans<<endl;
    int mid=l/2+(l%2==0?0:1);
    if(n%2==0){
        if(li-a[i].first==mid){
            cout<<ans<<endl;
            fclose(stdin);
             fclose(stdout);
            return 0;
        }

    }

   cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
