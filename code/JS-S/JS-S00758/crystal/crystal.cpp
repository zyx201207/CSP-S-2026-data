#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ans=0;
    bool flag_a=1;
    long long common_err=-1;
    cin>>n>>m;
    vector<long long> a(n);
    map<long long,long long> cnt;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        if(i==1){
            common_err=a[i]-a[i-1];
        } else if(i!=0){
            flag_a&=a[i]-a[i-1]==common_err;
        }
    }

    //special
    if(n==1) {cout<<1;return 0;}
    if(flag_a){
        //cout<<"FLAGA;\n";
        if(m<common_err){
            cout<<1;return 0;
        }
        ans=1;
        long long ad;
        for(ad=0;ad*(ad+1)/2*common_err<=m;ad++);
        cout<<ad;
        return 0;
    }

    sort(a.begin(),a.end());
    a.resize(unique(a.begin(),a.end())-a.begin());

    for(long long i=0;i<a.size();i++){
        long long cntp=0,r=m;
        cntp+=cnt[a[i]];
        for(long long bias=1;i-bias>=0;bias++){
            long long cur=i-bias;
            long long err=a[i]-a[cur];
            long long cost=err*cnt[a[cur]];
            if(cost <= r){
                cntp+=cnt[a[cur]];
                r-=cost;
                continue;
            } else{
                cntp+=(long long)(r/err);
                r-=(long long)(r/err)*err;
                break;
            }
        }
        if(ans<cntp){
            ans=cntp;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
