#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+3;
const long long INF=1e18+3;
long long a[maxn],pre[maxn],b[maxn];
long long minn=INF;
long long c[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    scanf("%d%lld",&n,&m);
    if(n==1){
        printf("%d",n);
        return 0;
    }
    bool f=false;
    bool f1=false;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(i>=3){
            if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
                f=true;
            }
        }
    }
    for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			f1=true;
		}
	}
	if(!f1){
	    printf("%d",n);
    return 0;
	}
    if(!f){
        int ans=0;
        long long p=a[2]-a[1];
        while(m>=p){
            m-=p;
            ans++;
        }
        printf("%d",ans+1);
    }else{
        int id;
        sort(a+1,a+1+n);
        int h=0;
        for(int i=1;i<=n;i++){
			if(a[i]-a[i-1]>m&&a[i+1]-a[i]>m)continue;
			b[++h]=a[i];
		}
        for(int i=1;i<=h;i++){
                pre[i]=pre[i-1]+b[i];
		}
		long long sum;
        for(int i=1;i<=h;i++){
            sum=(i-1)*b[i]-pre[i-1]+pre[n]-pre[i]-(n-i)*b[i];
            if(sum<minn){
                minn=sum;
                id=i;
            }
        }
        for(int i=1;i<=h;i++){
            c[i]=abs(b[i]-b[id]);
        }
        sort(c+1,c+1+h);
        int ans=0,p=1;
        while(m>=c[p]&&p<=h){
            if(m>=c[p]){
                m-=c[p];
                ans++;
            }
            p++;
        }
        printf("%d",ans);
    }
   return 0;
}

