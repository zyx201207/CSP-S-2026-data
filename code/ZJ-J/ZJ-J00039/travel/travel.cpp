//huan yin lai dao mian bei zha pian ji tuan
#include<bits/stdc++.h>
//#include<windows.h>
using namespace std;
string BaO,bAo,s1,s2;//BaO shi wo de tong xue,ta xue le san nian OI dou bu zhi dao sort han shu
//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);
//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);
//#include<windows.h>//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);
//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);
//#include<windows.h>//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);
//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);
//#include<windows.h>//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);
//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);
//#include<windows.h>//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);
//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);
//#include<windows.h>//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);
//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);
//#include<windows.h>
//froepen
//feropen
//fropen
//frepen
//freepon
//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);
//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);//int mian(){
//itn main(){
//freopen(".in","r",stdin);
//freopen(".out","r",stdout);//int mian(){
//itn main(){
//freopen(".in","w",stdin);
//freopen(".out","r",stdout);
//#include<windows.h>
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","r",stdout);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>BaO>>s1>>bAo>>s2;
	if(BaO[0]!=bAo[0]||BaO[1]!=bAo[1]){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(	!(
	('A'<=s2[2]&&s2[2]<='C'&&'A'<=s1[2]&&s1[2]<='C')
	||('D'<=s2[2]&&s2[2]<='F'&&'D'<=s1[2]&&s1[2]<='F')
	)	){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs(s1[2]-s2[2])==1||((int)s1[2]+(int)s2[2]=='D'+1-1+'F')){
		cout<<1;
	}
	else cout<<0;
	return 0;
} 
