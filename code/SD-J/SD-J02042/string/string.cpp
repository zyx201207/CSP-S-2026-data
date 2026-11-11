#include<iostream>
using namespace std;
char s[1000005];
long long len[1000005];
int n;
long long sum=0;
long long ans=0;
long long tol[1000005];
long long tor[1000005];
long long find(long long i){
	long long t=0;
	long long cnt=0;
	while(t<i){
		cnt++;
		t+=len[cnt];
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len[i]>>s[i];
		sum+=len[i];
		tol[i]=sum;
		tor[i]=sum-len[i]+1;
	}
	tol[n+1]=sum+1;
	tor[n+1]=sum+1;
	long long l,r;
	if(sum%2){
		l=sum/2;
		r=sum/2+2;
	}else{
		l=sum/2;
		r=sum/2+1;
	}
	long long li=find(l),ri=find(r);
	while(l>=1&&r<=sum&&li>0&&ri<=n){
		int flag;
		if(s[li]!=s[ri]){
			flag=1;
		}else{
			flag=0;
		}
		if(l-tol[li-1]>=tor[ri+1]-r){
			long long t=tor[ri+1]-r;
			l-=t;
			ans+=t*flag;
			r=tor[ri+1];
			ri++;
		}else{
			long long t=l-tol[li-1];
			r+=t;
			ans+=t*flag;
			l=tol[li-1];
			li--;
		}	
	}
	cout<<ans;
	return 0;
}
