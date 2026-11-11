#include<bits/stdc++.h>
using namespace std;
long long m,min_a=0x3f3f3f3f,max_a=-0x3f3f3f3f;
signed long long a[500010];
int n,ans=0;
bool u=true,v=true;
int f(long long x){
	int l=1,r=n,y=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid]<=x){
			y=mid;
			l++;
		}
		else r--;
	}
	return y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		//scanf("%d",&a[i]);
		cin>>a[i];
		if(a[i]!=i) u=false;
		if(i>2){
			if(!(a[i]-a[i-1]==a[i-1]-a[i-2])) v=false;
		}
	} 
	if(u){
		int s=0,i=0;
		while(s<=m and i<n) s+=++i;
		cout<<i;
		return 0;
	}
	else if(v){
		int s=0,i=0,j=0,k=a[2]-a[1];
		while(s<=m and j<n){
			j++;
			i+=k;
			s+=i;
		}
		cout<<j;
		return 0;
	}
	sort(a+1,a+n+1);
	min_a=a[1];
	max_a=a[n];
	for(long long i=min_a;i<=max_a;i++){
		int k=f(i),p=m,s=1;
		for(int j=k-1;j>=1;j--){
			if(p-(i-a[j])>=0){
				s++;
				p-=(i-a[j]);
			}
			else break;
		}
		ans=max(ans,s);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
