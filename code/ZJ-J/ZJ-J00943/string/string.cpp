#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,r;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ans+=a[i];
	}
	long long i=1,j=n,cnt=a[n],cn=0,k=0;
	ans=(ans&1?ans/2+1:ans/2);
	while(cn<=ans){
		long long w;
		if(cn+a[i]>ans){
			w=ans-cn;
			cn=ans+1;
		} else {
			cn+=a[i];
			w=a[i];
		}
		while(w){
			if(w>=cnt){
				w-=cnt;
				if(c[j]!=c[i])k+=cnt;
				j--;
				cnt=a[j];
			}else{
				cnt-=w;
				if(c[j]!=c[i])k+=w;
				w=0;
			}
		}i++;
	}
	cout<<k;
	return 0;
} 
