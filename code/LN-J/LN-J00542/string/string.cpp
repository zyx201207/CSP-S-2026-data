#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a,s;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    //cout<<n<<'\n';
    vector<node> st1,st2;
    long long a;
    char s;
    st1.push_back({0,0});
    for(int i=1;i<=n;i++){
        cin>>a>>s;
        s=s-'a';
        st1.push_back({a,s});
    }
    st2.push_back({0,0});
    for(int i=1;i<=n;i++){
        st2.push_back(st1[n-i+1]);
    }
    //for(int i=1;i<=n;i++){
    //    cout<<st1[i].a<<' '<<st2[i].a;
    //}
    long long l=0,r=0,li=0,ri=0,ans=0;
    while(li+ri<n){
        node ol=st1[li],orr=st2[ri],nl=st1[li+1],nr=st2[ri+1];
        if(l==r){
            li++,ri++;
            l+=nl.a,r+=nr.a;
            if(nl.s!=nr.s){
                ans+=min(nl.a,nr.a);
            }
        }else if(l<r){
            li++;
            if(nl.s!=orr.s){
                ans+=min(r,l+nl.a)-l;
            }
            l+=nl.a;
        }else if(l>r){
            ri++;
            if(nr.s!=ol.s){
                ans+=min(l,r+nr.a)-r;
            }
            r+=nr.a;
        }
        //cout<<ans<<' '<<l<<' '<<r<<' '<<li<<' '<<ri<<' '<<nl.a<<' '<<nr.a<<' '<<endl;
    }

    cout<<ans;
}
