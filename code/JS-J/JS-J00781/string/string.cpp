#include<bits/stdc++.h>
#define int long long
using namespace std;
int A[200005];
char c[200005];

int sc[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

struct str{
    int num;
    char c;
}a[200005];

int gcd(int x,int y){
    int ans=1;
    for(int i=1;i<=25;i++){
        if(x%sc[i]==0&&y%sc[i]==0){
            while(x%sc[i]==0&&y%sc[i]==0){
                x/=sc[i];
                y/=sc[i];
                ans*=sc[i];
            }
        }
    }
    return ans;
}

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++) cin>>A[i]>>c[i];
    int n=0;
    for(int i=1;i<=N;i++){
        n++;
        a[n].num=A[i];
        a[n].c=c[i];
        if(c[i]==c[i+1]){
            for(int j=i+1;j<=N;j++){
                if(c[j]!=c[j-1]) break;
                a[n].num+=A[j];
                i++;
            }
        }
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    int anss=a[1].num;
    string s="";
    for(int i=2;i<=n;i++){
        anss=gcd(anss,a[i].num);
    }
    for(int i=1;i<=n;i++){
       a[i].num/=anss;
    }
    for(int i=1;i<=n;i++){
       for(int j=1;j<=a[i].num;j++){
            s+=a[i].c;
       }
    }
    int ans=0;
    for(int l=0,r=s.size()-1;l<=r;l++,r--){
        if(s[l]!=s[r]) ans++;
    }
    cout<<ans*anss;
    return 0;
}
