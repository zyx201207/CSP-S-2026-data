#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool f(int mid){
	int time=0;//次数 
	int cnt=0;//完成数 
	for(int i=n;i>=1;i--){
		if(cnt>=mid) break;
		if(a[i]>mid) continue;
		if(a[i]==mid) cnt++;
		else if(a[i]<mid){
			cnt++;
			time+=(mid-a[i]);
		}
	}
	if(time<=m) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=a[1],r=a[n];
	int mid;//水晶的能量 
	for(;l<=r;){
		mid=(l+r)/2;
		if(f(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	
	int time=0;//次数 
	int cnt=0;//完成数 
	for(int i=n;i>=1;i--){
		if(cnt>=mid) break;
		if(a[i]>mid) continue;
		if(a[i]==mid) cnt++;
		else if(a[i]<mid){
			cnt++;
			time+=(mid-a[i]);
		}
	}
	cout<<cnt; 
	
	return 0;
}
