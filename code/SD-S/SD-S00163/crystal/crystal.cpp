#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
const int N=1e6;
long long n,k;
int ans=-(0x3f3f3f);
long long a[N]={0};
bool cmp(int a,int b){
	return a<b;
}
int Do(int x,int y){
	for(int i=x;i>=1;i--){
		if((a[i]==a[x])&&(i==(x-1))){
			continue;
		}else if((a[i]==a[x])&&(i!=(x-1))){
			y++;
		}else{
			if((k+a[i])>=a[x]){
				int t=a[x]-a[i];
				k-=t;
				y++;
//				cout<<a[i]<<' '<<k<<endl;
			}else{
//				cout<<y<<' '<<10011;
				return y;
			}
		}
	}
	return y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long b=k;
	for(int i=1;i<=n;i++){
		k=b;
		int y=0;
		if(a[i]!=a[i+1]){
			if(a[i]!=0&&i!=1&&a[i]==a[i-1]){
				y++;
			}
			y=Do(i,y);
			ans=max(ans,y);
//			cout<<endl;
		}
	}
	cout<<ans;
	return 0;
} 
