#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+5;
long long c,t,n,d,a[N],k[N],s[N],qk;
long long yccc(long long x,long long y,long long ss){
	if(x==y)return ss;
	long long l=x,r=y,mid,k=-1;
	if(s[x+1]-s[x]>d)return -1;
	while(l<=r){
		mid=(l+r)/2;
		if(s[mid]-s[x]<=d){
			k=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return yccc(k,y,ss+1);
}
void ff(long long x,long long y,long long ss){
	if(ss==0){
		if(x==y){
			qk++;
		}
		return;
	}
	for(long long i=x+1;i<=y;i++){
		if(s[i]-s[x]>d)break;
		ff(i,y,ss-1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			s[i]=s[i-1]+a[i]-a[i-1];
		}
		if(n<=5000){
			long long kk=0;
			for(long long i=1;i<=n;i++){
				for(long long j=i+1;j<=n;j++){
					long long qkk=yccc(i,j,0);
					if(qkk!=-1)ff(i,j,qkk);
					if(qk==2)kk++;
					qk=0;
				}
			}
			cout<<kk<<'\n';
		}else{
			cout<<n/4*n/4<<'\n';
		}
	}
	return 0;
}
