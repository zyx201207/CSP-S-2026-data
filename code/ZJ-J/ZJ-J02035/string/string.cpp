#include<bits/stdc++.h>
using namespace std;

int n;
char inc[200001];
int ina[200001];
long long total=0;

int jdz(int x,int y){
	if(x>=y) return x-y;
	else return y-x;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ina[i]>>inc[i];
		total+=ina[i];
	}
	long long mid=total/2;
	
	long long cnt=0;
	long long lrate=1;
	long long rrate=n;
	long long ll=1;
	long long rl=1;
	
	long long totalcnt=0;
	
	
	bool isbreak=false;
	while(1){
		if(totalcnt==mid) break;
		
		if(ll>ina[lrate]){
			lrate++;
			ll=1;
		}
		if(rl>ina[rrate]){
			rrate--;
			rl=1;
		}
		int jia=1;
		//long long jia=min(ina[lrate]-ll,ina[rrate]-rl)-1;
		//cout<<" debug ll="<<ll<<" rl="<<rl<<" lrate="<<lrate<<" rrate="<<rrate<<endl;
		if(inc[lrate]!=inc[rrate]){
			cnt+=jia;
		}
		ll+=jia;
		rl+=jia;
		
		totalcnt+=jia;
		//if(lrate==rrate&&jdz(ll,rl)<=1) break;
		//if(jdz(lrate,rrate)==1&&ll>ina[lrate]&&rl>ina[rrate]) break;
	}
	cout<<cnt;
	
	return 0;
}
/*
5
3 a
2 c
4 d
3 x
2 j

*/