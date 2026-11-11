#include<bits/stdc++.h>
using namespace std;
/*struct{
    int num;
    char ch;
} _STR;*/
vector<pair<long long,char> > a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;long long ans=0,v;char c;
    cin>>n>>v>>c;
    a.push_back({v,c});
    for(int i=1;i<n;i++){
        //i
        cin>>v>>c;
//        l+=v;
        /*if(c==a[i-1].second){
            a[i-1]={v+a[i-1].first,c};
            i--;n--;
        }
       // else */
            a.push_back({v,c});
    }
    int bg=0,ed=a.size()-1;
    while((ed-bg)>0){

        long long j=min(a[bg].first,a[ed].first);
        if(a[bg].second!=a[ed].second)ans+=j;
        //clog<<"[d] j="<<j<<" front:"<<a[0].second<<' '<<a[0].first<<" back:"<<a[a.size()-1].second<<' '<<a[a.size()-1].first<<endl;
        //i+=j-1;
        a[bg].first-=j;
        a[ed].first-=j;
        if(a[bg].first==0)bg++;
        if(a[ed].first==0)ed--;

    }
    cout<<ans;
}
