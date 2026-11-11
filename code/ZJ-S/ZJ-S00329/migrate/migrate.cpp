#include<bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
const int N=2e6+100;
const ll inf=1e9;
int c,n,m,ddd,q;
int a[N],d[N],f[N];
int al[N],ar[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        ar[i]=upper_bound(a+1,a+1+n,a[i]+m)-a-1;
        al[i]=lower_bound(a+1,a+1+n,a[i]-m)-a;
    }
    // for(int i=1;i<=n;i++){
    //     printf("%d %d&\n",al[i],ar[i]);
    // }
    if(c==11||c==12){
        int j=n,ysc=0;
        d[j]=0;
        f[j]=1;
        for(int i=al[j];i<=j-1;i++)d[i]=1,f[i]=1;
        for(int i=1;i<al[j];i++)d[i]=inf,f[i]=0;
        for(int i=al[j]-1;i>=1;i--){
            d[i]=d[ar[i]]+1;
            f[i]=f[ar[i]];
            for(int k=max(i+1,ar[i]-2);k<ar[i];k++){
                if(d[k]==d[ar[i]])f[i]+=f[k];
            }
        }
        for(int i=1;i<n;i++){
            if(f[i]==2)ysc+=i;
        }
        cout<<ysc<<'\n';
        return;
    }
    if(c==13||c==14){
        int ysc=0;
        for(int j=n;j>=n;j--){
            d[j]=0;
            f[j]=1;
            for(int i=al[j];i<=j-1;i++)d[i]=1,f[i]=1;
            for(int i=1;i<al[j];i++)d[i]=inf,f[i]=0;
            for(int i=al[j]-1;i>=1;i--){
                d[i]=d[ar[i]]+1;
                f[i]=f[ar[i]];
                for(int k=max(i+1,ar[i]-2);k<ar[i];k++){
                    if(d[k]==d[ar[i]])f[i]+=f[k];
                }
                if(f[i]==2){
                    ysc++;
                }
            }
            // printf("%d:\n",j);
            // for(int i=1;i<j;i++){
            //     printf("%d %d %d\n",i,d[i],f[i]);
            // }
        }
        cout<<ysc<<'\n';
        return;
    }
    if(n>=5001){
        cout<<"0\n";
        return;
    }
    int ysc=0;
    for(int j=n;j>=4;j--){
        d[j]=0;
        f[j]=1;
        for(int i=al[j];i<=j-1;i++)d[i]=1,f[i]=1;
        for(int i=1;i<al[j];i++)d[i]=inf,f[i]=0;
        for(int i=al[j]-1;i>=1;i--){
            d[i]=d[ar[i]]+1;
            f[i]=f[ar[i]];
            for(int k=max(i+1,ar[i]-2);k<ar[i];k++){
                if(d[k]==d[ar[i]])f[i]+=f[k];
            }
            if(f[i]==2){
                ysc++;
            }
        }
        // printf("%d:\n",j);
        // for(int i=1;i<j;i++){
        //     printf("%d %d %d\n",i,d[i],f[i]);
        // }
    }
    cout<<ysc<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>c;
    int t;
    cin>>t;
    while(t--)solve();
	return 0;
}
/*
g++ -std=c++14 -O2 -Wall -o migrate migrate.cpp
time ./migrate<migrate.in>migrate.out
*/