#include<bits/stdc++.h>
using namespace std;
int n,a[500005];
long long m,tong=-0x7f7f7f7f;
void f(long long x){
	if(x==m){
		int tong2=1,c=-0x7f7f7f7f; //tong2存重复最大的，c存重复的数 
		for(int i=1;i<=n;i++){
			if(i==1) c=a[i];
			if(i==n){
				if(a[i]==a[i-1]){
					tong2++;
					if(tong2>tong) tong=tong2;
				}
				else{
					if(tong2>tong) tong=tong2;
				}
			}
			if(a[i]==a[i-1]) tong2++;
			if(a[i]!=a[i-1]){
				if(tong2>tong) tong=tong2;
				tong2=1;
				c=a[i];
			}
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			a[i]++;
			f(x+1);
			a[i]--;
			return ;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	f(0);
	cout<<tong<<endl; 
	return 0;
} 
