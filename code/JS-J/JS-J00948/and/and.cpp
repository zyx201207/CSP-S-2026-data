#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200007],ans;
char s[200007][31];
int cnt[200007][31];
void bits2(int x,int i){
    int cnt=0;
    while(x!=0){
        s[i][cnt]=x%2+'0';
        cnt++;
        x/=2;
    }
    return;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    memset(s,'0',sizeof(s));
    for(int i=0;i<n;i++){
        bits2(a[i],i);
        for(int j=0;j<31;j++){
            cnt[i][31-j-1]=s[i][j]-'0';
        }
    }
    /*for(int i=0;i<n;i++){
        for(int j=0;j<31;j++){
            cout<<s[i][j];
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<31;j++){
            cout<<cnt[i][j];
        }
        cout<<endl;
    }*/
    int mx=0;
    while(cnt[n-1][mx]==0){
        mx++;
    }
    vector<int>b,b1,b2;
    bool ok=0;
    while(1){
        b.clear();
        int num=0;
        for(int i=n-1;i>=0;i--){
            if(cnt[i][mx]==1){
                num++;
                b.push_back(i);
            }
        }
        if(num>=m){
            break;
        }
        mx++;
    }
    int mm=mx+1;
    /*for(int i=0;i<b.size();i++){
        for(int j=0;j<31;j++){
            cout<<cnt[b[i]][j];
        }
        cout<<endl;
    }*/
    while(mm<31){
        if(!ok){
            b1.clear();
            int k=b.size();
            for(int i=0;i<k;i++){
                if(cnt[b[i]][mm]){
                    b1.push_back(b[i]);
                }
            }
            if(b1.size()>=m){
                ok=1;
            }
        }else{
            b.clear();
            int k=b1.size();
            for(int i=0;i<k;i++){
                if(cnt[b1[i]][mm]){
                    b.push_back(b1[i]);
                }
            }
            if(b.size()>=m){
                ok=0;
            }
        }
        mm++;
    }
    /*for(int i=0;i<b.size();i++){
        for(int j=0;j<31;j++){
            cout<<cnt[b[i]][j];
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<b1.size();i++){
        for(int j=0;j<31;j++){
            cout<<cnt[b1[i]][j];
        }
        cout<<endl;
    }
    cout<<endl<<ok<<endl;*/
    int k;
    if(ok)k=b1.size();
    else k=b.size();
    int c[31];
    //memset(c,1,sizeof(c));
    for(int i=0;i<31;i++){
        c[i]=1;
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<31;j++){
            if(ok){
                if(cnt[b1[i]][j]==0)c[j]=0;
            }else{
                if(cnt[b[i]][j]==0)c[j]=0;
            }
        }
    }
    /*for(int i=0;i<31;i++){
        cout<<c[i];
    }*/
    //cout<<endl;
    for(int i=1,j=30;j>=0;j--,i*=2){
        ans+=c[j]*i;
    }
    cout<<ans;
    return 0;
}
