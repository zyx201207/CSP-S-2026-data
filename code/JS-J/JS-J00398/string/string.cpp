#include<bits/stdc++.h>
using namespace std;
int n;pair<long long,char> c[200005];long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long x;char y;
        cin>>x>>y;
        c[i]={x,y};
    }
    int i=1;int j=n;
    while(i<j){
        long long v=c[i].first,vt=c[j].first;char w=c[i].second,wt=c[j].second;
        if(v==0)i++;
        if(vt==0)j--;
        if(w!=wt&&v<vt){
            ans+=v;
            c[j].first-=v;
            i++;
        }
        if(w!=wt&&v>vt){
            ans+=vt;
            c[i].first-=vt;
            j--;
        }
        if(w!=wt&&v==vt){
            ans+=v;
            c[i].first=0;
            c[j].first=0;
            i++;
            j--;
        }
        if(w==wt){
            if(v>vt){
                c[i].first-=vt;
                j--;
            }
            if(v<vt){
                c[j].first-=v;
                i++;
            }
            if(v==vt){
                c[i].first=0;
                c[j].first=0;
                i++;
                j--;
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
