#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt=0;
bool f1=1,f2=1;
long long a[200005];
char c[200005],c2[200005];
long long cishu2(){
	long long i=1,j=n,ans=0;
	while(i<=j){
		if(a[i]!=a[j])ans++;
		i++;j--;
	}
	return ans;
}
long long cishu(){
	long long i=1,j=n,ans=0;
	while(i<=j){
		if(c[i]!=c[j])ans++;
		i++;j--;
	}
	return ans;
}
long long cishu1(){
	long long i=1,j=cnt,ans=0;
	while(i<=j){
		if(c2[i]!=c2[j])ans++;
		i++;j--;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		a[0]=a[i];
		if(a[i]!=a[i-1]){
			f1=0;
		}
	}
	long long ans1=cishu();
	if(!ans1&&!cishu2()){
		cout<<0;
	}else if(f1){
		cout<<ans1*a[1];
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				c2[++cnt]=c[i];
			}
		}
		cout<<cishu1();
	}
	return 0;
}
