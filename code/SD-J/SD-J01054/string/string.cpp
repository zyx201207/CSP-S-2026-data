#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],p=-1,cnt,s;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%s",&a[i],&c[i]);
	}
	long long i=1,j=n;
	while(i<j){
		if(s){
			if(p==0){
				if(c[i]!=c[j]){
					cnt+=min(a[i],s);	
				}
				if(a[i]>=s){
					a[i]-=s;
					s=0;
					j--;
				}else{
					s-=a[i];
					i++;
				}
			}else if(p==1){
				if(c[i]!=c[j]){
					cnt+=min(a[j],s);	
				}
				if(a[j]>=s){
					a[j]-=s;
					s=0;
					i++;
				}else{
					s-=a[j];
					j--;
				}
			}
			if(s!=0){
				continue;	
			}
		}
		s=abs(a[i]-a[j]);
		if(s==0) p=-1;
		if(a[i]>a[j]) p=1;
		else if(a[j]>a[i]) p=0;
		if(c[i]!=c[j]){
			cnt+=min(a[i],a[j]);
		}
		if(p==-1){
			i++,j--;
		}else if(p==1) j--;
		else i++;
	}
	cout<<cnt;
	return 0; 
}
