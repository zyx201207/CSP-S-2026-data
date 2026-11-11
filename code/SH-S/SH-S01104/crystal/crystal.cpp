#include<bits/stdc++.h>
using namespace std;
long long qread(){
	char c=getchar();
	int flag=1;
	long long x=0;
	if(c=='-'){
		flag=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return flag*x;
}
long long n,m;
long long a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	n=qread();
	m=qread();
	for(int i=0;i<n;i++){
		a[i]=qread();
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(!i){
			s[i]=a[i];
		}
		else{
			s[i]=s[i-1]+a[i];
		}
	}
	long long ans=-1;
	for(long long i=0;i<n;i++){
		if(i==n-1||a[i]!=a[i+1]){
			int l=0,r=i-1;
			bool f=0;
			while(l<r){
				long long mid=((l+r)>>1);
				long long x=s[i]-a[i]-s[mid]+a[mid];
				if((i-mid)*a[i]-x<=m){
					r=mid-1;
					f=1;
				}
				else{
					l=mid+1;
					f=0;
				} 
				
			}
			if(l>0){
				l--;
			}
			long long x=s[i]-a[i]-s[l]+a[l];
			while(l<i&&(i-l)*a[i]-x>m){
				l++;
				x=s[i]-a[i]-s[l]+a[l];
			}
			ans=max(ans,i-l+1);
			
		}
		else{
			continue;
		}
	}
	cout<<ans;
	return 0;
}

