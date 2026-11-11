#include <bits/stdc++.h>
using namespace std;
int n,cur,ans;
string str;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char ch;
        cin>>x>>ch;
        for(int j=1;j<=x;j++){
            str+=ch;
        }
        cur+=x;
    }
    int l=0,r=cur-1;
    while(l<=r){
        if(str[l]!=str[r]) ++ans;
        l++;
        r--;
    }
    cout<<ans<<endl;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
struct qujian{
    long long l,r;
    char ch;
};
int n;
long long ans,cur_len;
vector<qujian> vec;
set<long long> fg;
vector<long long> fgv;
char solve(long long x){
    int h=0,t=n-1;
    while(h<=t){
        int mid=(h+t)/2;
        if(vec[mid].l<=x&&vec[mid].r>=x){
            return vec[mid].ch;
        }else if(vec[mid].l>x){
            t=mid-1;
        }else{
            h=mid+1;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("test.txt","r",stdin);
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long x;
        char ch;
        cin>>x>>ch;
        vec.push_back((qujian){cur_len+1,cur_len+x,ch});
        cur_len+=x;
    }
    for(int i=0;i<n;i++){
        cout<<vec[i].r<<" "<<cur_len-vec[i].r<<endl;
        if(vec[i].r>0)fg.insert(vec[i].r);
        if(cur_len-vec[i].r>0)fg.insert(cur_len-vec[i].r);
    }
    //fg.insert((cur_len+1)/2);
    for(set<long long>::iterator i=fg.begin();i!=fg.end();i++){
        fgv.push_back(*i);
        cout<<*i<<" ";
    }
    cout<<endl;
    for(int i=0;i<(int)fgv.size()-1;i++){
        if(fgv[i]>(cur_len+1)/2) break;
        cout<<"now count: "<<fgv[i]<<" "<<cur_len+1-fgv[i]<<" "<<solve(fgv[i])<<" "<<solve(cur_len+1-fgv[i])<<endl;
        if(solve(fgv[i])!=solve(cur_len+1-fgv[i])){
            ans+=fgv[i+1]-fgv[i];
            cout<<i<<" "<<fgv[i]<<" "<<fgv[i+1]-fgv[i]<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
*/
