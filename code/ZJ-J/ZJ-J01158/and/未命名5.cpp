#include<bits/stdc++.h>
using namespace std;
int n,m,mx=-1,cnt,jiesen;
string a[200010],ans="",s,sss;
string jia(string x,string y){
	string ans="";
	char dajie;
	int zdw=0,jinwei=0,len=min(x.size(),y.size());
	for(int i=1;i<=len;i++){
		zdw=(x[x.size()-1]-'0')+(y[y.size()-1]-'0')+jinwei;
//		cout<<zdw<<endl;
		if(zdw>=10){
			jinwei=1;
		}else{
			jinwei=0;
		}
		dajie=(zdw%10+'0');
		ans=dajie+ans;
		x.erase(x.size()-1,1);
		y.erase(y.size()-1,1);
	}
	ans=x+y+ans;
	return ans;
}
string chu_yi2(string x1) {
	string shang="";
	int zui_gao_wei=0,tui_wei=0;
	while(x1!="") {
		zui_gao_wei=x1[0]-'0'+tui_wei;
		shang+=(zui_gao_wei/2+'0');
		if(zui_gao_wei%2) {
			tui_wei=10;
		} else {
			tui_wei=0;
		}
		x1.erase(0,1);
	}
	while(shang[0]=='0'&&shang.size()>1) {
		shang.erase(0,1);
	}
	return shang;
}
string cheng2(string x1) {
	string ji="";
	x1="0"+x1;
	int zui_di_wei=0,jin_wei=0;
	while(x1!="") {
		zui_di_wei=x1[x1.size()-1]-'0';
		char jie_pi=(zui_di_wei*2+jin_wei)%10+'0';
		ji=jie_pi+ji;
		if(zui_di_wei*2+jin_wei>=10) {
			jin_wei=1;
		} else {
			jin_wei=0;
		}
		x1.erase(x1.size()-1,1);
	}
	return ji;
}
string f_10zhuan2(string x) {
	string ans="";
	while(x!="0") {
		if((x[x.size()-1]-'0')%2==1) {
			ans="1"+ans;
		} else {
			ans="0"+ans;
		}
		x=chu_yi2(x);
	}
	while(ans[0]=='0'&&ans.size()>1) {
		ans.erase(0,1);
	}
	return ans;
}
string f_2zhuan10(string x){
	string ans="0",ii="1";
	for(int i=x.size()-1;i>=0;i--){
		if(x[i]=='1'){
			ans=jia(ans,ii);
		}
		ii=cheng2(ii);
	}
	while(ans[0]=='0'&&ans.size()>1) {
		ans.erase(0,1);
	}
	return ans;
}
int main() {
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		a[i]=f_10zhuan2(a[i]);
		jiesen=a[i].size();
		mx=max(mx,jiesen);
	}
	for(int i=1; i<=n; i++) {
		s="";
		for(int j=1; j<=mx-a[i].size();j++) {
			s=s+"0";
		}
		a[i]=s+a[i];
	}
	for(int i=1; i<=mx;i++) {
		ans="0"+ans;
	}
	for(int i=0; i<mx; i++) {
		cnt=0;
		for(int j=1; j<=n; j++) {
			cnt+=a[j][i]-'0';
		}
		if(cnt>=m) {
			ans[i]='1';
			for(int j=1;j<=n;j++){
				if(a[j][i]=='0'){
					a[j]="00000000000000000000000000000000";
				}
			}
		}
	}
	cout<<f_2zhuan10(ans);
	return 0;
}