#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,m,mid=0;
	cin>>n>>m;
	int list[100005];
	int middle=0;	//求离mid最近的中间值 
	int cha=0;
	int final_cha=0;
	for(int i=0;i<n;i++){
		cin>>list[i];
	}
	int head=list[0];
	int tail=list[n-1];
	
	int ans=(tail-head)/2-1;
	cout<<ans<<'\n'; 
	for(int i=0;i<n;i++){
		mid=(list[0]+list[n-1])/2;
}
	cha=abs(list[0]-mid)/2;
	//记录保存的位置 
	int direction = 0;
	for(int j=0;j<n;j++){
			//如果下一位的差比这一位更小的话，下一位变成新中间值
			if(abs(list[j]-mid)<=cha){
				cha=abs(list[j]-mid);	//中间变量 
			} else {
				direction=j;
				break;
			}
		}
	return 0; 
}
