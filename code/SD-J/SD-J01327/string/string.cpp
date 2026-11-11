#include<bits/stdc++.h>
using namespace std;
int n;
char s[200010];
int a[200010];
char op[5];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&a[i],op);
		s[i]=op[0];
	}		
	int l=1,r=n;
	while(l<r){
		if(s[l]==s[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]==a[r]){
				l++,r--;
			}else{
				a[r]-=a[l];
				l++;
			}
		}else{
			ans+=min(a[l],a[r]);
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]==a[r]){
				l++,r--;
			}else{
				a[r]-=a[l];
				l++;
			}			
		}
	}
	printf("%lld",ans);
	return 0;
}
