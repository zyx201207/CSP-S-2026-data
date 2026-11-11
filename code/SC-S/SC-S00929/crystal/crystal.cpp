//
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500010],ans=1,b[500010],c=2;
bool cmp(int x,int y){
	return x<=y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000){
		ll x=a[2]-a[1],d=1,e=1;
		while(m>=0){
			if(m<(e*x)){
				break;
			}
			d++;
			e+=d;
		}
		cout<<d;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	/*
	if(n>5000){
		ll x=a[2]-a[1],d=1,e=1;
		while(m>=0){
			if(m<(e*x)){
				break;
			}
			d++;
			e+=d;
		}
		cout<<d;
		return 0;
	}
	*/
	//sort(b+2,b+n+1);
	while(c<=n){
		m-=ans*b[c];
		c++;
		if(m<0){
			break;
		}
		ans++;
	}
	printf("%lld",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}