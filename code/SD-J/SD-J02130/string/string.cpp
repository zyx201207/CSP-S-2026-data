#include<bits/stdc++.h>
using namespace std;
long long a[200010]={0};
long long b[200010]={0},ans=0;
char c[200010];
char d[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,len=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
		b[n-i+1]=a[i];
		d[n-i+1]=c[i];
	}
	long long m=0,am=1,bm=1,cnt=0;
	while(1){
		m=min(a[am],b[bm]);
		if(cnt+m>len/2){
			if(c[am]!=d[bm]) ans+=len/2-cnt;
			break;
		}
		cnt+=m;
		if(c[am]!=d[bm]) ans+=m;
		if(a[am]<b[bm]){
			am++;
			b[bm]-=m;
		}else if(a[am]>b[bm]){
			bm++;
			a[am]-=m;
		}else{
			am++;
			bm++;
		}
	}	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
