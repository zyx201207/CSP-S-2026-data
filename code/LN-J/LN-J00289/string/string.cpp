#include <bits/stdc++.h>
using namespace std;

string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int T;
    cin>>T;
    int t=T;
    char xx;
    bool fl=0;
    if(T==1){
        cout<<0<<endl;
        return 0;
    }
    while(T--){
        long long n;
        char x;
        cin>>n>>x;
        if(T==t)xx=x;
        if(n>=1e4&&fl<=1){
            if(x!=xx)fl=2;
            else{
                fl=1;
                continue;
            }

        }
        string ss;
        for(int i=0;i<n;i++)ss+=x;
        s+=ss;
    }
    if(fl=1){

    }
    long long cnt = 0;
    long long sz=s.size();
    for(long long i=0;i<(long long)(sz+1)/2;i++){
        if(s[i]!=s[sz-i-1]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct node{
    int st,ed;
    char x;
    int fl;
}a[N];
vector<node>ans;
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }

    long long la=0;
    for(int i=1;i<=n;i++){
        long long s;
        char c;
        cin>>s>>c;
        a[i].st=la+1;
        a[i].ed=la+s;
        a[i].x=c;
        a[i].fl=0;
        la=a[i].ed;
    }
    for(int i=2;i<=n;i++){
        if(a[i].x==a[i-1].x){
            a[i-1].fl=1;
            a[i].st=a[i-1].st;

        }
    }
    for(int i=1;i<=n;i++){
        if(a[i].fl==0){
            ans.push_back({a[i]});
        }
    }
    if(ans.size()==1){
        cout<<0<<endl;
        return 0;
    }
    n=ans.size();
    int maxx=ans.back().ed;
    string s;
    for(int i=0;i<n;i++){
        for(int j=ans[i].st;j<=ans[i].ed;j++){
            s+=ans[i].x;
        }
    }
    long long cnt=0;
    for(int i=0;i<(maxx+1)/2-1;i++){
        if(s[i]!=s[s.size()-i-1])cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
/*
int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }

    long long la=0;
    for(int i=1;i<=n;i++){
        long long s;
        char c;
        cin>>s>>c;
        a[i].st=la+1;
        a[i].ed=la+s;
        a[i].x=c;
        a[i].fl=0;
        la=a[i].ed;
    }
    for(int i=2;i<=n;i++){
        if(a[i].x==a[i-1].x){
            a[i-1].fl=1;
            a[i].st=a[i-1].st;

        }
    }
    for(int i=1;i<=n;i++){
        if(a[i].fl==0){
            ans.push_back({a[i]});
        }
    }
    if(ans.size()==1){
        cout<<0<<endl;
        return 0;
    }
    n=ans.size();
    int maxx=ans.back().ed;
    int mid=(maxx+1)/2;
    int Mid;
    for(int i=0;i<n;i++)
        if(ans[i].ed>=mid&&ans[i].st<=mid)Mid=i,ans[i].fl=-1;
    bool ok=1;
    long long tot=0;
    for(int i=0;i<n;i++){
        if(!ok)break;
        if(ans[i].fl==-1)ok=0;
        if(ok){
            for(int j=n-1;j>=0;j--){
                if(ans[j].st<=(n-ans[i].ed+1)&&ans[j].ed>=(n-ans[i].st+1)&&ans[i].x!=ans[j].x){
                    tot+=ans[i].ed-ans[i].st+1;
                }
            }
        }
    }
    cout<<tot<<endl;
    return 0;
}
*/

*/
