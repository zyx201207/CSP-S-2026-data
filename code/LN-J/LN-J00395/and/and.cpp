#include<bits/stdc++.h>
using namespace std;
int a[200010];
int cnt[40];
bool cmp(int a,int b){
    return a>=b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<30;j++){
            cnt[j]+=(a[i]>>j)&1;
        }
    }
    sort(a+1,a+1+n,cmp);
    bool ok=true;
    if(m==1){
        cout<<a[1];
        return 0;
    }
    int st=0;
    for(int i=0;i<=29;i++){
           // cout<<cnt[i]<<" "<<i<<endl;
        if(cnt[i]>=m) {
            st=i;
            ok=false;
        }
    }
    //cout<<st<<endl;
    if(ok){
        cout<<0<<endl;

        return 0;
    }
    vector<int> now;
    for(int i=1;i<=n;i++){
        if((a[i]>>st)&1){
            now.push_back(a[i]);
            //cout<<a[i]<<endl;
        }
    }
    //for(int i=0;i<now.size();i++) cout<<now[i];
    //for(int w:now) cout<<w<<endl;
    int i=st;
    for(;i>=0;){
          //  cout<<i<<"cha"<<endl;
        vector<int> neew;
        for(int w:now){
            if((w>>i)&1){
                neew.push_back(w);
            }
        }
        now=neew;
        //for(int w:now) cout<<w<<endl;
        bool have=true;
        //cout<<i<<"po";
        for(int j=i-1;j>=0;j--){
            cnt[j]=0;
            for(int w:now){
                if((w>>j)&1)
                   {
                       cnt[j]++;
                       // cout<<"?"<<j;
                   }
            }
            if(cnt[j]>=m){
                i=j;
                //cout<<"??"<<endl;
                have=false;
                break;
            }
            //cout<<j<<"jimadanba";
        }
        if(have){
            break;
        }
    }
    /*vector<int> ans(200010);
    for(int w:now){
        if((w>>i)&1){
            ans.push_back(w);
        }
    }*/
    //for(int w:now) cout<<w;
    int sum=now[0]&now[1];
    for(int i=2;i<now.size();i++){
        sum&=now[i];
    }
    cout<<sum<<endl;



}
