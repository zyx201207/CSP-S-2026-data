#include<bits/stdc++.h>
using namespace std;
long long n,m,s[300005],b[500005];
stack <long long> a;
bool ish(stack <long long> a,long long b){ //寻找是否已经有卡牌
	while(!a.empty()){
		if(a.top()==b){
			return 1;
		}
		a.pop();
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>b[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(ish(a,b[j])){  //如果有，就pop所有之后的卡
				while(a.top()!=b[j]){
					a.pop();
				}
			}else{  //否则加入新卡
				a.push(b[j]);
			}
		}
		//一轮结束，开始统计
		bool iy[300005]={0};  //默认都为0（桶）
		while(!a.empty()){
			iy[a.top()]=1;  //把遇到的放水桶里
			a.pop();
		}
		for(int j=1;j<=m;j++){
			s[j]+=iy[j];  //小桶->大桶
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;  //Ohhhhhhh yes!
}
