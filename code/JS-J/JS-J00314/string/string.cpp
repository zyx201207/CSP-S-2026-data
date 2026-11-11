#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3;
char ch[N];
long long n;
long long a[N];
void work(){
    string s="";
    long long nm=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++) s+=ch[i];
        nm+=a[i];
    }
    string ss=s;
    reverse(s.begin(),s.end());
    if(ss==s){
        cout<<0;
        return;
    }
    int res=0;
    for(int i=0;i<nm/2;i++){
        if(ss[i]!=s[i]) res++;
    }
    cout<<res;
    return;
}
long long sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    bool ob=true;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
        sum+=a[i];
        if(a[i]>500) ob=false;
    }
    if(ob){
        work();
        return 0;
    }
    sum/=2;
    long long ans=0;
    int t=1;cout<<sum<<' ';
    for(int i=1;i<=n;i++){
        long long nd=a[i];
        //sum-=nd;
        if(sum<=0) break;
        while(nd){
            bool ok=true;
            if(ch[i]==ch[n-t+1]) ok=false;
            if(nd<=a[n-t+1]){
                a[n-t+1]-=nd;
                if(ok){
                    ans+=nd;
                    sum-=nd;
                }
                nd=0;

            }
            else {
                nd-=a[n-t+1];
                if(ok){
                    ans+=a[n-t+1];
                    sum-=a[n-t+1];
                }
                t++;
                a[n-t+1]=0;
                ch[n-t+1]=ch[i];

            }

        }


    }
    cout<<ans;

    return 0;
}

