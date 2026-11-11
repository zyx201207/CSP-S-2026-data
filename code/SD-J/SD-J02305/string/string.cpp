#include <bits/stdc++.h>
using namespace std;
struct info{
	long long num;
	char x;
};
info a[210000];
long long s[210000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].x;
		s[i]=s[i-1]+a[i].num;
	}
	long long ans=0;
	long long mid=s[n]/2;
	long long l=1,r=s[n];
	int j=n,i=1;
	while(l<=mid&&r>mid){
		if(a[i].x!=a[j].x){
			long long x1=s[i]-l+1,y1=r-s[j-1];
			if(s[j-1]<mid) y1=r-mid;
			if(s[i]>mid) x1=mid-l+1;
			if(x1<y1){
				ans+=x1;
				i++;
				l+=x1,r-=x1;
			}
			else if(x1==y1){
				ans+=x1;
				i++,j--;
				l+=x1,r-=y1;
			}
			else if(x1>y1){
				ans+=y1;
				j--;
				l+=y1,r-=y1;
			}
			if(l>s[i]) i++;
			if(r<s[j]) j--;
		}
		else{
			int x1=s[i]-l+1,y1=r-s[j-1];
			if(s[j-1]<mid) y1=r-mid;
			if(s[i]>mid) x1=mid-l+1;
			if(x1<y1){
			//	ans+=x1;
				i++;
				l+=x1,r-=x1;
			}
			else if(x1==y1){
			//	ans+=x1;
				i++,j--;
				l+=x1,r-=y1;
			}
			else if(x1>y1){
			//	ans+=y1;
				j--;
				l+=y1,r-=y1;
			}
			if(l>s[i]) i++;
			if(r<s[j]) j--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
