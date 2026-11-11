//string
#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
const int N=2e5+10;
struct node{
	ll st,ed;//记录某一字符的开始位置和结束位置，下标从0开始 
	char c;
}range[N];
ll n;

void solveA(){
	string st;
	for(int i=1;i<=n;i++){
		for(int j=range[i].st;j<=range[j].ed;j++){
			st.push_back(range[i].c);
		}
	}
	//小样例 
	ll cnt=0;
	ll len=st.size();
	ll i,j;
	if(len&1){
		i=j=len/2;
	}
	else{
		i=len/2-1;
		j=len/2;
	}
	while(i>=0 && j<len){
		if(st[i]!=st[j]) cnt++;
		i--,j++;
	}
	cout<<cnt;
	return;
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	ll last_pos=-1;
	ll sum=0;
	for(int i=1;i<=n;i++){
		ll a;
		cin>>a;
		char c;
		cin>>c;
		range[i].st=last_pos+1;
		range[i].ed=a+last_pos;
		last_pos+=a;
		range[i].c=c;
		//for(int i=1;i<=a;i++) st.push_back(c);
	}
	
	//测试 
	//cout<<st;
	/*for(int i=1;i<=n;i++){
		cout<<'['<<range[i].st<<','<<range[i].ed<<"] "<<range[i].c<<'\n';
	}*/
	
	if(n<=10){
		solveA();
		return 0;
	}
	
	//正解
	//思路：按区间，保存某个字符所在的区间，然后从中间开始进行比对
	//哨兵
	range[0].ed=-1; 
	range[n+1].st=range[n].ed+1;
	//计算长度
	ll len=range[n].ed+1; 
	//第一步：找到中间点
	ll point1,point2;
	if(len&1){
		point1=point2=len/2;
	}
	else{
		point1=len/2-1;
		point2=len/2;
	}
	//第二步：找到中间点所在的区间的编号
	ll left_idx=-1,right_idx=-1;
	for(int i=1;i<=n;i++){
		if(range[i].st<=point1 && range[i].ed>=point1) left_idx=i;
		if(range[i].st<=point2 && range[i].ed>=point2) right_idx=i;
		//找到所在的区间的编号了 
		if(left_idx!=-1 && right_idx!=-1) break;
	} 
	//第三步：进行比对
	ll cnt=0;
	while(point1>=0 && point2<len && left_idx>=1 && right_idx<=n){
		//分情况讨论
		//1.相同
		if(range[left_idx].c==range[right_idx].c){
			//将point1移到前一个区间的右端点或将point2移到后一个区间的左端点，具体看谁离得近
			ll move1=point1-range[left_idx-1].ed;
			ll move2=range[right_idx+1].st-point2;
			if(move1<=move2){
				point1=range[left_idx-1].ed;
				left_idx--;
				point2+=move1;
				if(point2>range[right_idx].ed) right_idx++;
			}
			else{
				point2=range[right_idx+1].st;
				right_idx++;
				point1-=move2;
				if(point2<range[left_idx].ed) left_idx--;
			}
		} 
		//不相同
		if(range[left_idx].c!=range[right_idx].c){
			//将point1移到前一个区间的右端点或将point2移到后一个区间的左端点，具体看谁离得近
			ll move1=point1-range[left_idx-1].ed;
			ll move2=range[right_idx+1].st-point2;
			//cout<<range[right_idx+1].st<<' '<<point2<<' '<<range[right_idx+1].st-point2<<'\n';
			if(move1<=move2){
				point1=range[left_idx-1].ed;
				left_idx-=1;
				point2+=move1;
				if(point2>range[right_idx].ed) right_idx++;
				cnt+=move1;
			}
			else{
				point2=range[right_idx+1].st;
				right_idx++;
				point1-=move2;
				if(point2<range[left_idx].ed) left_idx--;
				cnt+=move2;
			}
		}
	} 
	cout<<cnt;
	return 0;
}
