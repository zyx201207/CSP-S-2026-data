#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
int num[212345];
char a[212345];
void f(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>a[i];
	}
	int i=1,j=n;
	while(i<=j){
//		printf("%lld %lld %lld %lld\n",i,j,num[i],num[j]);
		if(a[i]!=a[j]){
			ans+=min(num[i],num[j]);
		}
		if(num[i]<num[j]){
			num[j]-=num[i];
			i++;
		}else{
			num[i]-=num[j];
			j--;
		}
//		if(num[i]==0) i++;
//		if(num[j]==0) j--;
	}
	cout<<ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	f();
	return 0;
}
