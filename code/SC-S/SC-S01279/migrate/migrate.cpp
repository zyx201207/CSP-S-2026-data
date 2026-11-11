#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[1000005],juli[100005],cnt=0,len;
int same(int step,int total_len,int now_len,int cnt,int now_step,int shang_ci){
	if(step==now_step&&total_len==now_len) return cnt++; 
	else if(step==now_step) return same(step,total_len,now_len-shang_ci,cnt-1,now_step-1,shang_ci);
	for(int j=1;j<=d;j++){ //枚举步长 
		return same(step,total_len,now_len+j,cnt,now_step+1,j)+same(step,total_len,now_len,cnt,now_step,shang_ci);
	}
}
int metre(int xx,int yy,int stopcnt,int total_len){
	if(xx==yy)  return same(stopcnt+1,total_len,0,0,1,0);
	for(int i=xx;i<=yy;i++){ //i枚举停留小岛 
		for(int j=i+1;j<=yy;j++){ //j为目标点
		    if(x[j]-x[i]>d){
		    	//可以在j-1点休息 
		    	if(j-1==i) return 0;
		    	metre(j-1,yy,stopcnt+1,total_len);
			}
		} 
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cnt=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<n;j++){
				len=x[j]-x[i];
				if(metre(i,j,0,len)>1) cnt++;
			}
		}
		cout<<cnt/3;
	} 
	return 0;
}