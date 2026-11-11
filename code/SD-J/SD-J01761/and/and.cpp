#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],n,m;
string numtostring(int x,int m){
	string a="";
	int cnt=0;
	while(x>0){
		if(x%2==1){
			a="1"+a;
			cnt++;
			if(cnt>m)return "";
		}else{
			a="0"+a;
		}
		x/=2;
	}
	if(cnt>m||cnt<m)return "";
	while(a.size()<n){
		a="0"+a;
	}
	return a;
}
void FCB(int n){
	int ans=0;
	for(int i=1;i<=pow(2,n);i++){
		int x=i;
		if(numtostring(x,m)!=""){
			string gay=numtostring(x,m);
			int jianguangwuhen=0,now=0;
			for(int j=0;j<gay.size();j++){
				if(gay[j]=='1'){
					if(jianguangwuhen==0){
						jianguangwuhen++;
						now=a[j+1];
					}else{
						now=now&a[j+1];
						if(now==0)break;
					}
				}
			}
			ans=max(ans,now);
		}
	}
	cout<<ans;
}
void ARS(){
	sort(a+1,a+1+n);
	cout<<a[n-1];
}
void PSG(){
	int ans=a[1];
	for(int i=2;i<=n;i++){
		ans=ans&a[i];
	}
	cout<<ans;
}
void INT(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
	cout<<ans;
}
bool judgeA(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1&&a[i]!=3&&a[i]!=7&&a[i]!=15&&a[i]!=31&&a[i]!=63&&a[i]!=127&&a[i]!=255&&a[i]!=511&&a[i]!=1023&&a[i]!=2047&&a[i]!=4095&&a[i]!=8191&&a[i]!=16383&&a[i]!=32767&&a[i]!=65535&&a[i]!=131071&&a[i]!=262143&&a[i]!=524287&&a[i]!=1048575){
			return false;
		}
	}
	return true;
}
void BAY(){
	sort(a+1,a+1+n);
	cout<<a[n-2];
}
bool judgeB(){
	if(n!=2&&n!=4&&n!=8&&n!=16&&n!=32&&n!=64&&n!=128&&n!=256&&n!=512&&n!=1024&&n!=2048&&n!=4096&&n!=8192&&n!=16384&&n!=32768&&n!=65536&&n!=131072){
		return false;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1)return false;
	}
	return true;
}
void ESP(){
	sort(a+1,a+1+n);
	cout<<a[n-3];
}
void ARG(){
	sort(a+1,a+1+n);
	for(int i=n;i>=2;i--){
		if(a[i]==a[i-1]){
			cout<<a[i];
			return ;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		FCB(n);
		return 0;
	}
	if(m==1){
		ARS();
		return 0;	
	}
	if(m==n){
		PSG();
		return 0;
	}
	if(m==2){
		INT();
		return 0;
	}
	if(judgeA()==true){
		BAY();
		return 0;
	}
	if(judgeB()==true){
		ESP();
		return 0;
	}
	ARG();
	return 0;
}
/*1-5二进制枚举  完成 

6选最大值  完成 

7直接算  完成 

8-10  O(n*n) 完成 

13特殊性质A：排序后输出第n-m大的 完成 

14，15特殊性质B：排序后输出第n-m-1大的 完成

16，17排序后去看有没有相等的两个数 完成

估分:60 
*/
