#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,sum;
struct node{
	long long x;
	char c;	
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		sum+=a[i].x;
	}
	long long l=1,r=sum;
	long long p1=1,p2=n;
	while(l<=sum/2&&r>=sum-sum/2+1){
		if(a[p1].x>a[p2].x){
			l+=a[p2].x;
			r-=a[p2].x;
			if(a[p1].c!=a[p2].c)ans+=a[p2].x;
			a[p1].x-=a[p2].x;
			p2--;
		}
		else if(a[p1].x<a[p2].x){
			l+=a[p1].x;
			r-=a[p1].x;
			if(a[p1].c!=a[p2].c)ans+=a[p1].x;
			a[p2].x-=a[p1].x;
			p1++;
		}
		else{
			l+=a[p1].x;
			r-=a[p1].x;
			if(a[p1].c!=a[p2].c)ans+=a[p1].x;
			p1++;
			p2--;
		}
	}
	cout<<ans;
	return 0;
}















