#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long a[N];
bool flaga=true,flagb=true,flagc=true;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //cout<<log2(a[i]+1)<<endl;
        if(pow(2,(int)log2(a[i]+1))!=a[i]+1)flaga=false;
        if(pow(2,(int)log2(n))!=n||a[i]!=i-1)flagb=false;
        if(a[i]>=4)flagc=false;
    }
    //if(flagb)cout<<"Yes";
    sort(a+1,a+1+n);
    if(n<=20){
        long long ans=-1,txt1;
        for(int i=1;i<=pow(2,n);i++){
            txt1=pow(2,20)-1;
            int txt=i;
            int num=0,id=1;
            while(txt){
                if(txt%2==1){
                    num++;
                    txt1&=a[id];
                }
                txt/=2;
                id++;
            }
            if(num!=m)continue;
            else ans=max(ans,txt1);
            //cout<<i<<":"<<ans<<"\n";
        }
        cout<<ans;
        return 0;
    }
    else if(n<=2000){
        if(m==1){
            cout<<a[n];
        }
        else if(m==n){
            long long ans=pow(2,20)-1;
            for(int i=1;i<=n;i++)ans&=a[i];
            cout<<ans;
        }
        else if(m==2){
            long long ans=-1;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    ans=max(ans,a[i]&a[j]);
                }
            }
            cout<<ans;
        }
        return 0;
    }
    else if(n<=200000){
        if(m==n-1){

        }
        else if(flaga==true){
            cout<<a[n-m+1];
        }
        else if(flagb==true){
            int ans=n-1,txt=1;
            if(m==1){
                cout<<ans;
                return 0;
            }
            for(int i=1;i<m;i++){
                if(pow(2,(int)log2(i))==i&&ans!=0){
                    //cout<<i<<":"<<ans<<" "<<txt<<endl;
                    ans-=txt;
                    txt*=2;

                }
            }
            cout<<ans;
        }
        else if(flagc==true){
            int txt[4]={0,0,0,0};
            for(int i=1;i<=n;i++){
                txt[a[i]]++;
            }
            if(m<=txt[3])cout<<3;
            else if(m<=txt[3]+txt[2])cout<<2;
            else if(m<=txt[3]+txt[1])cout<<1;
            else cout<<0;
        }
    }
    return 0;
}
