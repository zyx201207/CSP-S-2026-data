#include<bits/stdc++.h>
using namespace std;
long long dp[200010],a[200010];
bool v[200010],vv[200010];
string s[200010];
long long n,m;
long long cnt=1;
int main(){
    ios::sync_with_stdio(NULL);
    cout.tie(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        long long x=a[i];
        if(x==0)s[i]="0";
        long long ct=0;
        while(x){
            s[i]=char(x%2+'0')+s[i];
            x/=2;
            ct++;
        }
        cnt=max(ct,cnt);
    }
    for(int i=1;i<=n;i++){
    	while(s[i].size()<cnt){
    		s[i]='0'+s[i];
		}
	}
    long long cut=0;
    for(int i=0;i<cnt;i++){
        long long cot=0;
        for(int j=1;j<=n;j++){
            if(s[j][i]=='0'&&!v[j]){
                vv[j]=1;
                cot++;
            }
        }
        if(cot<=(n-m)-cut){
            cut+=cot;
            for(int j=1;j<=n;j++){
                v[j]+=vv[j];
            }
        }
        memset(vv,0,sizeof(bool)*(n+2));
    }
    long long ans;
    bool f=1;
    for(int i=1;i<=n;i++){
        if(!v[i]){
            if(f){
                ans=a[i];
                f=0;
            }else{
                ans=ans&a[i];
            }
        }
    }
    cout<<ans;
    return 0;
}
