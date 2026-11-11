#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
long long cnt[200005];
char c[200005];
long long lenc[200005]={};
int find(int l,int r,long long tar)
{
	int mid;
	while(l<r){
		mid=(l+r)>>1;
		if((mid>0?tar>lenc[mid-1]:true)&&tar<=lenc[mid])return mid;
		else if(lenc[mid]<tar)l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	int tmp=0;
	for(int i=0;i<n;i++){
		scanf("%lld %c",&cnt[tmp],&c[tmp]);
		if(tmp==0){
			lenc[tmp]=cnt[tmp];
			tmp++;
		}else{
			if(c[tmp]==c[tmp-1]){
				cnt[tmp-1]+=cnt[tmp];
				lenc[tmp-1]=lenc[tmp-1]+cnt[tmp];
			}else{
				lenc[tmp]=lenc[tmp-1]+cnt[tmp];
				tmp++;
			}
		}
	}
	n=tmp;
	if(n==1){
		printf("0");
		return 0;
	}
	long long midnum=lenc[n-1]/2;
	int mid=find(0,n-1,midnum);
	long long ans=0;
	long long ct1=0,ct2=lenc[n-1];
	while(ct1<midnum&&ct2>midnum){
		int i=find(0,n-1,ct1+1),j=find(0,n-1,ct2-1);
		if(c[i]!=c[j]){
			if(cnt[i]<cnt[j]){
				ans+=cnt[i];
				c[i]=c[j];
				ct1+=cnt[i];
				ct2=lenc[n-1]-ct1;
			}else{
				ans+=cnt[j];
				c[j]=c[i];
				ct2-=cnt[j];
				ct1=lenc[n-1]-ct2;
			}
		}
		if(cnt[i]!=cnt[j]){
			int dif=abs(cnt[i]-cnt[j]);
			ans+=dif;
			if(cnt[i]<cnt[j]){
				cnt[j]-=dif;
				cnt[j-1]+=dif;
				lenc[j]-=dif;
				lenc[j-1]+=dif;
			}else{
				cnt[i]-=dif;
				cnt[i+1]+=dif;
				lenc[i]-=dif;
				lenc[i+1]+=dif;
			}
			ct1+=cnt[i];
			ct2=lenc[n-1]-ct1;
		}
	}
	printf("%lld",ans);
	return 0;
}
