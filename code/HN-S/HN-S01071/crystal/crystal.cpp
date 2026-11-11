#include<bits/stdc++.h>
using namespace std;
const long long h=1e5*5+5,f=1e12+1;
long long m,a[h],b[h],minnum[2][2],ans=1;
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	minnum[1][0]=f;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		b[i]=abs(a[i]-a[i-1]);
		if(b[i]<minnum[1][0]){
			minnum[1][0]=b[i];
			minnum[1][1]=i;
		}
	}
//	cout<<minnum[1][0]<<" "<<minnum[1][1]<<" ";
	int l=1,r=1;
	while(m>=0){
		if(minnum[1][1]==1){
			for(int i=minnum[1][1]+1;i<n;i++){
				if(m>=0){
					m=m-a[i]+a[minnum[1][1]];
					if(m>=0){
						ans++; 
					}
					else{
						break;
					}
				}
			}
		}
		else{
			if(a[minnum[1][1]-l]<a[minnum[1][1]+r]){
				m=m-a[minnum[1][1]]+a[minnum[1][1]-l];
				if(m>=0){
					ans++; 
				}
				else{
					break;
				}
				l++;
			}
			else{
				m=m+a[minnum[1][1]]-a[minnum[1][1]+r];
				if(m>=0){
					ans++; 
				}
				else{
					break;
				}
				r++;
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
