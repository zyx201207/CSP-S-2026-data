//²élonglong scanf Ä£Êý 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5; 
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long len=0;
	for(int i=1;i<=n;i++){
		scanf("%lld %s",&a[i],&c[i]);
		len+=a[i];
	}
	long long l=1,r=n,lc=a[1],rc=a[n],ans;
	if(c[l]==c[r])	ans=0;
	else	ans=min(a[l],a[r]);
	while(l<r-1){
		//if(lc>len/2||rc>len/2)	break;
		if(lc<=rc){
			l++;
			lc+=a[l];
			if(c[l]!=c[r]){
				if(lc<=rc)	ans+=a[l];
				else	ans+=rc-(lc-a[l]);
			}
		}
		else{
			r--;
			rc+=a[r];
			if(c[l]!=c[r]){
				if(lc>rc)	ans+=a[r];
				else 	ans+=lc-(rc-a[r]);
			}
		}
	}
	printf("%lld",ans);
} 
