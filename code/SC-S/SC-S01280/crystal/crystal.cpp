#include <bits/stdc++.h>
using namespace std;
const int MAXN=21;
long long a[MAXN],n,m,b[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];											
	}
	long long max1=-1;
	if(n<=16){
		for(long long i=pow(2,n)-1;i>=0;i--){
			memset(b,0,sizeof(b));
			long long tmp=i,cnt1=0,cnt2=1;
			while(tmp){
				if(tmp&1){
					b[++cnt1]=a[cnt2];
				}
				cnt2++;
				tmp>>=1;
			}
			long long ans=0,f=b[(cnt1+1)/2];
			for(int j=1;j<=cnt1;j++){
				if(b[j]-f>=0){
					ans+=b[j]-f;
				}else{
					ans+=f-b[j];
				}
			}
			if(ans<=m){
				cout<<cnt1;
				break;
			}
		}
	}
	return 0;
}