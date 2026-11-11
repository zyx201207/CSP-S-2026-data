#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll d,x[2000010];
int c,t,n,f[2000010];
int find_next(int s,int e){

    int s1=e;
    while(s1>=s&&f[s1]==f[e]) s1--;
    return s1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin>>c>>t;
    while(t--){
        memset(f,0,sizeof(f));
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        f[1]=f[0]=0,f[n+1]=n;
        for(int i=n;i>=1;i--){
            for(int j=f[i+1];j>=1;j--){
                if(x[i]-x[j]>d) break;
                f[i]=j;
            }
        }
        //for(int i=1;i<=n;i++) cout<<f[i];
        //cout<<endl;

        int sum=0;
        for(int i=n;i>=2;i--){
            int q=find_next(f[i],i),p=f[q];
            if(p==0&&q==0) break;
            //cout<<f[i]<<' '<<i<<' '<<p<<' '<<q<<endl;
            if(f[i]+1!=q) continue;
            //cout<<f[i]<<' '<<i<<' '<<p<<' '<<q<<endl;
            sum+=f[i]-p;
            //cout<<f[i]<<' '<<i<<' '<<sum<<endl;
            while(1){
                q=find_next(p,q);
                if(p==q) p=f[q],sum+=q-p;
                else break;
            }

        }

        cout<<sum<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
