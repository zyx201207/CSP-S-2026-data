#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long a[N],pre[N];
long long ans=0;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		pre[i]=pre[i-1]+a[i];
	}
	int l=0,r=n+1;
	long long len=pre[n];
	//cout<<len;
	while(pre[l]<=(len/2)&&(pre[n]-pre[r-1])<=(len/2)){
		long long lenl=pre[l],lenr=pre[n]-pre[r-1];
		if(lenl==len/2&&lenr==(len/2))break;
		if(lenl>lenr){
			r--;
			if(pre[n]-pre[r-1]>(len)/2){
				if(c[l]!=c[r])ans+=(lenl-lenr);
				while(pre[l+1]<=len/2){
					l++;
					if(c[l]!=c[r])ans+=pre[l]-pre[l-1];

				}
				break;
			}
			if(c[l]!=c[r]){
				if(pre[n]-pre[r-1]<lenl)ans+=pre[n]-pre[r-1]-lenr;
				else ans+=(lenl-lenr);
			}
		}
		else{
			l++;
			if(pre[l]>(len)/2){
				if(c[l]!=c[r])ans+=(lenr-lenl);
				while(pre[n]-pre[r-2]<=len/2){
					r--;
					if(c[l]!=c[r])ans+=pre[r-1]-pre[r];
				}
				break;
			}
			if(c[l]!=c[r]){
				if(pre[l]<lenr)ans+=pre[l]-lenl;
				else ans+=(lenr-lenl);
			}
		}
		
	}
	
	cout<<ans;
}

