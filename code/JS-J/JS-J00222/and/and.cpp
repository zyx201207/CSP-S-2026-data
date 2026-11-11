#include<bits/stdc++.h>
using namespace std;
int a[10005],e[10005][40],n,m,sum[2005],maxn=-100,b[10005][10005],mx=-100,cnt[20],s=0,t=0,f;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=40;j++){
            e[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
        int j=0;
        while(a[i]!=0){
            e[i][j]=a[i]%2;
            if(e[i][j]==1) sum[i]++;
            j++;
            a[i]/=2;
        }

        maxn=max(maxn,sum[i]);
    }
   if(m==1) cout<<maxn<<endl;
   else if(m==2){
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
                for(int k=1;k<=40;k++){
                    if(a[i]==a[j]){
                        b[i][j]=a[i];
                        break;
                    }
                  if(e[i][k]==e[j][k]&&e[i][k]>=0) b[i][j]++;
        }

        mx=max(mx,b[i][j]);
    }
    }cout<<mx<<endl;
   }

   else if(m==n){


        for(int i=0;i<40;i++){
                int fl=0;

            for(int j=0;j<n-1;j++){
                if(e[j][i]!=e[j+1][i]) fl=1;
            }

            if(fl==0) s++;
        }
        cout<<s<<endl;
   }
   else if(m==n-1){
    for(int i=1;i<=n;i++){
        for(int j=0;j<40;j++){
            f=0;

            for(int k=0;k<n-1;k++){
                    if(k==i) continue;
                if(e[k][j]!=e[k][j]) f=1;
            }
        }if(f==0) t++;

   }
   cout<<t;
   }


		return 0;
	}
