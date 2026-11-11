#include<bits/stdc++.h>
using namespace std;
unsigned long long n,x[200005],len,cnt,k,sl=1,sr=1,ans,ll[200005],rr[200005],o,cnt1;
char c[200005],cl[200005],cr[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
		len+=x[i];
	}
	for(int i=1;i<=n;i++){
		if(cnt+x[i]>=len/2){
			k=i;
			ll[i]=len/2-cnt;
			cl[i]=c[i];
			break;
		}
		cnt+=x[i];
		ll[i]=x[i];
		cl[i]=c[i];
	}
	for(int i=n;i>=1;i--){
	if(cnt1+x[i]>=len/2){
		rr[++o]=len/2-cnt1;
		cr[o]=c[i];
		break;
	}	
	cnt1+=x[i];
	rr[++o]=x[i];
	cr[o]=c[i];
	}
	len=len/2*2;
	while(len!=0){
		bool f=0;
		if(ll[sl]>rr[sr])
		f=1;
	if(cl[sl]==cr[sr]){
		if(f==1){
			ll[sl]-=rr[sr];
			len-=2*rr[sr];
			sr++;
		}
		if(f==0){
			rr[sr]-=ll[sl];
			len-=2*ll[sl];
			sl++;
			if(sr==0)
			sr++;
		}
	}
	else{
		if(f==1){
			ans+=rr[sr];
			len-=2*rr[sr];
			ll[sl]-=rr[sr];
			sr++;
		}
		if(f==0){
			ans+=ll[sl];
			len-=2*ll[sl];
			rr[sr]-=ll[sl];
			sl++;
			if(sr==0)
			sr++;
		}
	}
	}
	cout<<ans;
	return 0;
}
