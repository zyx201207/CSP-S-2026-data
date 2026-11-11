#include<bits/stdc++.h>
using namespace std;
int n,cnt,mm=-1,ans;
string s,mn,kl,ls,tot,qhf,hhf;
const int maxn=2e5;
int bu[1000];
struct hw{
    int l;
    char gh;
}a[maxn];
bool cmp(hw a,hw b){
    return a.l>b.l;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].l>>a[i].gh;
        cnt+=a[i].l;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        bu[a[i].gh]+=a[i].l;
    }
    for(int i=0;i<n;i++){
        mm=max(bu[a[i].gh],mm);
        if(mm=bu[a[i].gh]){
            mn=a[i].gh;
        }
    }
    for(int i=0;i<n;i++){
        if(bu[i]>0&&bu[i]){
            for(int j=0;j<bu[i];j++){
                s+=(char)i;
            }
        }
    }
    for(int i=0;i<s.size();i++){
        mn+=s[i];
        if(s[i]!=s[i+1]){
            break;
        }
    }
    for(int i=mn.size();i<s.size();i++){
        kl+=s[i];
        if(i==ceil((s.size())/2.0)){
            break;
        }
    }
    for(int i=mn.size()+kl.size();i<s.size();i++){
        ls+=s[i];
    }
    tot+=mn;
    tot+=kl;
    tot+=ls;
    for(int i=0;i<ceil((s.size())/2.0);i++){
        qhf+=tot[i];
    }
    for(int i=ceil((s.size())/2.0);i<s.size();i--){
        hhf+=tot[i];
    }
    for(int i=0;i<ceil((s.size())/2.0);i++){
        if(qhf!=hhf){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

