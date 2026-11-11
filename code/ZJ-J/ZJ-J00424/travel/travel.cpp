#include<bits/stdc++.h>
using namespace std;
//你的freopen去掉注释了吗（预估100分）
/*
吾日三省吾身：
freopen去掉注释了吗？
关闭输入输出流了吗？
编译选项开O2优化了吗

*/
string c1,c2;
int s1,s2;
char w1,w2;
bool f1,f2;
bool solve(){
	if(w1==(w2-1))return true;
	if(w1==(w2+1))return true;
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>w1>>c2>>s2>>w2;
	if(w1=='A'||w1=='B'||w1=='C')f1=1;
	if(w2=='A'||w2=='B'||w2=='C')f2=1;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1!=s2){
		cout<<"1000";
		return 0;
	}
	if(f1!=f2){
		cout<<"1100";
		return 0;
	}
	if(!solve()){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}