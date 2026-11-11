#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int n;
long long m;
long long a[600000];
long long pre[600000];
int ma;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(int i = 1;i <= n;i++){
		int lt = 1,rt = i;
		while(lt<rt){
			int mid = (lt+rt)>>1;
			if(pre[i]-pre[mid-1]+m<a[i]*(i-mid+1)){
				lt=mid+1;
			}else{
				rt=mid;
			}
		}
		ma = max(ma,i-lt+1);
	}
	cout<<ma<<'\n';
	return 0;
} 
