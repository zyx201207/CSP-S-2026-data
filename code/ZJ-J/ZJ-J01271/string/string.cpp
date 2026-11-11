#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],ans,num;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
		if(c[i-1]==c[i]){
			a[i-1]+=a[i];
			i--;
			n--;
		}
	}long long j=n,p=0;
	for(long long i=1,sum=0;i<=n&&sum<num/2;sum+=a[i],i++){
		long long o=a[i];
		while(o){
			if(o<a[j]-p){
				if(c[i]!=c[j])ans+=o;
				p+=o;
				o=0;
			}else{
				if(c[i]!=c[j])ans+=a[j]-p;
				o-=a[j--]-p;
				p=0;
			}
		}
	}cout<<ans;
	return 0;
}
