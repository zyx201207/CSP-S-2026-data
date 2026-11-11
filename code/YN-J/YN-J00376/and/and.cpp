#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m;
long long a[N];
long long ans;
bool p=1;

bool cmp(long long x,long long y){
	return x>y;
}

void tp(){
	ans=a[1];
	for(int i=1;i<=m;i++){
		ans=ans&a[i];
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&(a[i]-1!=a[i-1])){
			p=0;
		}
	}
	sort(a+1,a+1+n,cmp);
	if(p){
		tp();
		return 0;
	}
	ans=a[1];
	bool s=0;
	long long len=1;
	for(int i=1;len<=m;i++){
		if(!s){
			for(int j=1;j<i;j++){
				if((a[j]&a[i])==a[i]){
					len+=2;
					ans=a[i];
					s=1;
					break;
				}
			}
			continue;
		}
		if((ans&a[i])==a[i]){
			ans=a[i];
			len++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
