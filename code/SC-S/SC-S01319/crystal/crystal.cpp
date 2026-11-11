#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,cnt,sum;
const int N=5e5+100;
LL a[N],c[N];
int main(){
	freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		c[a[i]]++;
	}
	sort(a+1,a+n+1);
	LL mid=0;
	if(n%2!=0){
		mid=a[n/2+1];
	}
	
	if(n%2==0){
		LL ma=0;
		for(int k=0;k<=1;k++){
			mid=a[n/2+k];cnt=0;
			sum=0;
			cnt+=c[mid];
			for(int i=k+1;i<=n/2+k;i++){
				if(mid==0 && sum<m){
					sum+=abs(a[i]);
					cnt++;
					if(sum>m){
						sum-=abs(a[i]);
						cnt--;
					}
				}else
					if(a[i]>0 && sum<m && mid>0){
						sum+=abs(mid-a[i]);
						cnt++;if(sum>m){
							cnt--;
							sum-=abs(mid-a[i]);
						}
						
					}else if(a[i]<0 && sum<m  && mid>0){
						sum+=mid+abs(a[i]);
						if(sum>m){
							cnt--;sum-=mid+abs(a[i]);
						}
						cnt++;
					}else if(a[i]<0 && sum<m  && mid<0){
						sum+=mid-a[i];cnt++;
						if(sum>m){
							cnt--;	sum-=abs(a[i])-abs(mid);
						}
					}
			}
			ma=max(ma,cnt);
		}
		printf("%lld",ma);
		return 0;
	}
	
	cnt+=c[mid];
	for(int i=1;i<=n/2;i++){
		if(mid==0){
			sum+=abs(a[i]);
			
		}
		if(a[i]>0 && sum<m && mid>0){
			sum+=abs(mid-a[i]);
			cnt++;if(sum>m){
				cnt--;
				sum-=abs(mid-a[i]);
			}
			
		}else if(a[i]<0 && sum<m  && mid>0){
			sum+=mid+abs(a[i]);
			if(sum>m){
				cnt--;sum-=mid+abs(a[i]);
			}
			cnt++;
		}else if(a[i]<0 && sum<m  && mid<0){
			sum+=mid-a[i];cnt++;if(sum>m){
				cnt--;	sum-=abs(a[i])-abs(mid);
			}
		}
	}
	printf("%lld",cnt);
	return 0;
	
}