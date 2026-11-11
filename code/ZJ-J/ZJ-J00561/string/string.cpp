#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int a[N],n,b[N];
char c[N];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=a[i];
	}
	int i=n,j=1;
	for(;i>=1&&i>j;i--){
		while(b[i]-b[j]>0&&i>j){
			b[i]-=b[j];
			if(c[i]!=c[j])ans+=b[j];
			b[j]=0;
			j++;
		}
		if(b[i]-b[j]<=0){
			b[j]-=b[i];
			if(c[i]!=c[j])ans+=b[i];
			b[i]=0;
		}
	}
	cout<<ans;
	return 0;
}