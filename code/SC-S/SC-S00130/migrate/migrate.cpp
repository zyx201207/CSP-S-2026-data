#include<bits/stdc++.h>
using namespace std;

int id,q;
int n;
long long m,ans;
long long a[200500];
int to[200500];
long long c[200500];

int cnt,step;

void dfs( int now,int t,int st ){
	if( st>step ) return;
	if( now==t ){
		++cnt;
		return;
	}
	for( int i=now+1; i<=to[now]; ++i ){
		dfs( i,t,st+1 );
		if( cnt>2 ) return;
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&id,&q);
	while( q-- ){
		scanf("%d %d",&n,&m);
		for( int i=1; i<=n; ++i ){
			scanf("%lld",&a[i]);
		}
		to[0]=1;
		for( int i=1; i<=n; ++i ){
			for( int j=to[i-1]; j<=n; ++j ){
				if( a[j]-a[i]>m ) break;
				to[i]=j;
			}
		}
		if( id<=10 ){
			ans=0;
			for( int i=1; i<=n; ++i ){
				for( int j=i+1; j<=n; ++j ){
					cnt=0,step=0;
					for( int k=i; k<=j; ++k ){
						k=to[k];
						++step;
					}
					dfs( i,j,0 );
					if( cnt==2 ) ++ans;
				}
			}
			printf("%lld\n",ans);
		}
		else if( id==11 or id==12 ){
			ans=0;
			for( int i=1; i<=1; ++i ){
				for( int j=i+1; j<=n; ++j ){
					cnt=0,step=0;
					for( int k=i; k<=j; ++k ){
						k=to[k];
						++step;
					}
					dfs( i,j,0 );
					c[n-j+1]=1;
				}
			}
			int cc=0;
			for( int i=n; i>=1; --i ){
				if( c[i]) ++cc;
				ans+=cc;
			}
			printf("%lld\n",ans);
		}
		else{
			printf("1\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}