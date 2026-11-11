#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long l,q[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
		l+=a[i];
		q[i]=q[i-1]+a[i];
	}
	long long i=1,bl=l/2,j=n,si=a[1],sj=a[n];
	while(q[i-1]+1<=bl && i!=j){
		if(c[i]!=c[j]){
			long long x=min(si,sj);
			ans+=x;
			if(si==x && sj!=x){
				i++;
				si=a[i];
				sj-=x;
			}else if(sj==x && si!=x){
				j--;
				sj=a[j];
				si-=x;
			}else{
				i++;
				j--;
				si=a[i];
				sj=a[j];
			}
		}else{
			long long x=min(si,sj);
			if(si==x && sj!=x){
				i++;
				si=a[i];
				sj-=x;
			}else if(sj==x && si!=x){
				j--;
				sj=a[j];
				si-=x;
			}else{
				i++;
				j--;
				si=a[i];
				sj=a[j];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 