#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=2e5+10;
struct node{
	long long a;
	string s;
}b[N];
signed main(){
	 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,num=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>b[i].a>>b[i].s;
		num+=b[i].a;
	}
	int up=0,down=0,ans=0;//up:向上找次数 ，down向下找次数 
	int zh=ceil(num*1.0/2);//zh代表中间点下标
	for(int i=1;i<=t;i++){
		if(zh-b[i].a<=0){
			down=zh;
			break;
		}else{
			zh-=b[i].a;
		}
	} 
	zh=ceil(num*1.0/2);
	for(int i=num;i>=t;i--){
		if(zh-b[i].a<=0){
			up=zh;
			break;
		}else{
			zh-=b[i].a;
		}
	} 
	string tmp1=b[zh].s,tmp2=b[zh].s;
	for(int i=1;i<=num/2;i++){
		if(up==0){
			up=b[zh-i].a;
			tmp1=b[zh-i].s;
		}
		if(down==0){
			down=b[i+zh].a;
			tmp2=b[zh+i].s;
		}
		if(tmp1!=tmp2){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

