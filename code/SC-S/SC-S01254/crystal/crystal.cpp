#include<bits/stdc++.h>
#define N 500005
using namespace std;
long long n,m,sum,idx2,idx1,ans=1;
long long a[N];
long long mx[N],mi[N];
double mid;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	mid=1.0*sum/n;
	for(int i=1;i<=n;i++){
		if(a[i]>mid)mx[++idx1]=a[i];
		else if(a[i]<mid)mi[++idx2]=a[i];
		else{
			ans++;
			mi[++idx2]=a[i];
		}
	}
	sort(mi+1,mi+1+idx2,cmp);
	sort(mx+1,mx+1+idx1);
	int jz,l,r;
	if(mid-mi[1]<mx[1]-mid){
		jz=mi[1];
		l=2,r=1;
	}
	else{
		jz=mx[1];
		l=1,r=2;
	}
	while(l<=idx2||r<=idx1){
		if(ans==n)break;
		if(m<jz-mi[l]&&m<(mx[r]-jz)*ans)break;
		if(m<=0)break;
		if((m>=jz-mi[l])&&(jz-mi[l]<(mx[r]-jz)*ans)&&l<=idx2){
			m-=(jz-mi[l]);
			l++;
			ans++;
		}
		else{
			m-=(mx[r]-jz)*ans;
			jz=mx[r];
			r++;
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}