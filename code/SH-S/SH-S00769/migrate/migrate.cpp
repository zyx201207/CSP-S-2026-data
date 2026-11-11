#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T;
int n,d;
int x[2000002];
int cnt,cha;
int ans;
int a[2000002];
int num,numr,jiu;
int l,r;
int sum=0;
void dc(int cha){
	cnt=d/cha;
	ans=max(0LL,n-(cnt+cnt-1));
	printf("%lld\n",ans);
}
int check(int num,int numr){
	sum=0;
	int L=l,R=r-1,res1=-1,res2=-1;
	if(x[R]-x[L]<=2*d){
		while(L<=R){
			int mid=(L+R)>>1;
			if(x[r-1]-x[mid]<=d&&x[mid]-x[l]>=d){
				res1=mid;
				R=mid-1;
			}else if(x[r-1]-x[mid]>d) L=mid+1;
			else R=mid-1;
		}
		L=l;
		R=r-1;
		while(L<=R){
			int mid=(L+R)>>1;
			if(x[r-1]-x[mid]<=d&&x[mid]-x[l]>=d){
				res2=mid;
				L=mid+1;
			}else if(x[r-1]-x[mid]>d) L=mid+1;
			else R=mid-1;
		}
	}
	if(res1!=-1&&res2!=-1){
		if(res2-res1+1>=2){
			sum=(r-1-res2)*(res1-l);
			sum+=num*(r-1-res2)+numr*(res1-l);
			return sum;
		}else{
			return res1;
		}
	}
	return 2;
}
void bl(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	ans=0;
	cha=x[2]-x[1];
	bool flag=true;
	for(int i=3;i<=n;i++){
		if(x[i]-x[i-1]!=cha){
			flag=false;
			break;
		}
	}
	if(flag==true){
		dc(cha);
		return;
	}
	num=numr=0;
	jiu=0;
	l=r=1;
	for(r=1;r<=n+1;r++){
		if((l==r||x[r]-x[r-1]<d)&&r!=n+1&&numr==0&&x[r]-x[l]<=2*d){
			jiu=1;
			continue;
		}
		if(x[r]-x[r-1]==d){
			if(jiu==0) num++;
			else numr++;
		}
		ans+=check(num,numr);
		l=r;
		num=numr=jiu=0;
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		bl();
	}
	return 0;
}
