#include<bits/stdc++.h>
using namespace std;
long long a,b,s[200010],ans=0;
void x(long long v,long long ne,long long an){
	if(ne==0){
		ans=max(ans,an);
		return ;
	}
	if(v>=a){
		return ;
	}
	for(long long i=v+1;i<=a;i++){
		x(i,ne-1,an&s[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>a>>b;
	for(long long i=1;i<=a;i++){
		cin>>s[i];
	}
	sort(s+1,s+1+a);
	if(b==1){
		cout<<s[a];
		return 0;
	}else if(b==a){
		long long k;
		k=s[1];
		for(long long i=2;i<=a;i++){
			k=k&s[i];
		}
		cout<<k;
		return 0;
	}else if(b==2){
		long long max1=0;
		for(long long i=1;i<a;i++){
			for(long long j=i+1;j<=a;j++){
				max1=max(max1,s[i]&s[j]);
			}
		}
		cout<<max1;
		return 0;
	}else if(a>2000){
		cout<<0;
		return 0;
	}
	x(0,b,1e9-1);
	cout<<ans;
	return 0;
}
