#include<bits/stdc++.h>
#define int long long
using namespace std;
int kk[200005];
char j[200005];
struct node{
	int l,r;
	char c;
};
node a[800005];
int l[800005],r[800005];
int cnt2=0;
void update(int lc,int rc){
	l[++cnt2]=lc;
	r[cnt2]=rc;
}
int cnt=0;
int sum[128][800005];
int qh(int l1,int r1,char x){
	int tl=upper_bound(l+1,l+1+cnt,l1)-l-1;
	int tr=lower_bound(r+1,r+1+cnt,r1)-r;
	int ret=sum[x][tr]-sum[x][tl-1];
	if(a[tl].c!=x && a[tl].l<l1) ret-=l1-a[tl].l;
	if(a[tr].c!=x && a[tr].r>r1) ret-=a[tr].r-r1;
	return ret;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,sum1=0;cin>>n;
	int sl=0;
	for(int i=1;i<=n;i++){
		cin>>kk[i]>>j[i];
		sum1+=kk[i];
	}
	for(int i=1;i<=n;i++){
		int k=kk[i];
		char p=j[i];
		int tl=sl+1,tr=sl+k;
		sl=tr;
		if(!(sum1&1)){
			if(tl<=sum1/2+1 && tr>=sum1/2+1){
				a[++cnt]={tl,sum1/2,p};
				a[++cnt]={sum1/2+1,tr,p};
				update(tl,sum1/2);
				update(sum1/2+1,tr);
			}else{
				a[++cnt]={tl,tr,p};
				update(tl,tr);
			}
			continue;
		}
		if(tl<=ceil(sum1*1.0/2) && tr>=ceil(sum1*1.0/2)){
			if(tl<ceil(sum1*1.0/2))a[++cnt]={tl,ceil(sum1*1.0/2)-1,p};
			a[++cnt]={ceil(sum1*1.0/2),ceil(sum1*1.0/2),p};
			if(tl<ceil(sum1*1.0/2))update(tl,ceil(sum1*1.0/2)-1);
			update(ceil(sum1*1.0/2),ceil(sum1*1.0/2));
			tl=ceil(sum1*1.0/2)+1;
		}
		if(tl<=tr){
			a[++cnt]={tl,tr,p};
			update(tl,tr);
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int j='a';j<='z';j++){
			sum[j][i]=sum[j][i-1]+(a[i].c!=j)*(a[i].r-a[i].l+1);
		}
	}
	int ans=0;
	for(int i=1;a[i].l<=sum1/2;i++){
		ans+=qh(sum1-a[i].r+1,sum1-a[i].l+1,a[i].c);
	}
	cout<<ans;
	return 0;
} 
