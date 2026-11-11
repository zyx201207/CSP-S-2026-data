#include <bits/stdc++.h>
using namespace std;
long long b[500010],chong[500010];
int main(){
	long long n,m,cnt=1;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	chong[1]=1;
	for(long long i=2;i<=n;i++){
		if(b[i-1]==b[i]){
			chong[i]=chong[i-1];
		}else{
			chong[i]=i;
		}
	}
	for(int i=n;i>1;i--){
		long long m1=m;
		long long q=i-1,maxv=1;
		while(m1!=0&&q>=1){	
			int mo=b[i]-b[q],shu=1;
			if(chong[q]!=1){
				shu=q-chong[q]+1;
			}
			if(m1<=mo*shu){	
				maxv+=m1/mo;
				m1=0;
			}else{
				maxv+=shu;
				m1-=mo*shu;
				q=chong[q];
			}
			q--;
		}
		cnt=max(cnt,maxv);
	}
	cout<<cnt;
	return 0;
}
