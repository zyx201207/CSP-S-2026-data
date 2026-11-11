#include<bits/stdc++.h>
using namespace std;
int a[200005][35];
int b[35];
int x[200005];
long long n,m;
int maxx=-1;
void dfs(int dep,int ans,int k){
    if(k==m){
        maxx=max(maxx,ans);
        return ;
    }
    if(dep>n) return ;
    dfs(dep+1,ans&x[dep],k+1);
    dfs(dep+1,ans,k);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(m==1){
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            maxx=max(maxx,x);
        }
        cout<<maxx;
        return 0;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxx=max(maxx,x[i]&x[j]);
            }
        }
        cout<<maxx;
        return 0;
    }else if(n==m){
        int ans=2147483647;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            ans&=x[i];
        }
        cout<<ans;
        return 0;
    }else if(m==n-1){
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            int ans=2147483647;
            for(int j=1;j<=n;j++){
                if(j==i) continue;
                ans&=x[j];
            }
            maxx=max(ans,maxx);
        }
        cout<<maxx;
        return 0;
    }else if(n<=20){
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        dfs(1,2147483647,0);
        cout<<maxx;
        return 0;
    }



    bool AK=0,AC=0;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        if(x[i]>=4) AK=1;
        int k=1;
        int xx=x[i];
        while(xx>0){
            b[k++]=xx%2;
            if(b[k]==0) AC=1;
            xx/=2;
        }
        //for(int j=2;j<=k;j++) a[i][j-1]=b[k-j+1];
        for(int j=2;j<=k;j++) a[i][j-1]=b[j-1];
        a[i][33]=k-1;
        maxx=max(maxx,k-1);
        /*
        for(int j=2;j<=k;j++) cout<<a[i][j-1];
        cout<<endl;
        */
    }
    if(AK==0){
        int o=0,p=0,q=0;
        for(int i=1;i<=n;i++){
            if(x[i]==3) o++;
            if(x[i]==2) p++;
            if(x[i]==1) q++;
        }
        m-=o;
        if(m<=0) cout<<3;
        else if(m<=p) cout<<2;
        else if(m<=q) cout<<1;
        else cout<<0;
        return 0;
    }
    if(AC==0){
        int ans=2147483647;
        sort(x+1,x+1+n);
        for(int i=1;i<=m;i++){
            ans&=x[i];
        }
        cout<<ans;
        return 0;
    }


    long long ans=2147483647;
    int k=n;
    bool ok=1;
    for(int i=maxx;i>=1;i--){
        int s=0;
        for(int j=1;j<=k;j++){
            if(a[j][i]==1){
                s++;
            }
        }
        if(s<m) continue;
        if(s=m){
           // cout<<s<<endl;
       // cout<<i<<endl;
            for(int j=1;j<=k;j++){
                //cout<<x[j]<<' '<<1<<endl;
                if(a[j][i]==1){
                    ans&=x[j];
                    //cout<<x[j]<<' '<<endl;
                }
            }
            ok=0;
            break;
        }else if(s>m){
            int b=0;
            for(int j=1;j<=k;j++){
                if(a[j][i]==1){
                    b++;
                    for(int y=1;y<=a[j][33];y++){
                        a[b][y]=a[j][y];
                        x[b]=x[j];
                    }
                }
            }
            k=b;
        }
    }
    if(ok==0) cout<<ans;
    else cout<<0;
    return 0;
}
