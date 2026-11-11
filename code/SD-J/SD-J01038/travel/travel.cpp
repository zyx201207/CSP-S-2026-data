#include<bits/stdc++.h>
using namespace std;
bool onerow(string s1,string s2){
	char s1a=s1[2],s2a=s2[2];
	if(s1a>=65 and s1a<=67 and s2a>=65 and s2a<=67)return true;
	if((s1a=='D' and s2a=='F') or (s1a=='F' and s2a=='D'))return true;
	return false;
}bool near(string s1,string s2){
	char s1a=s1[2],s2a=s2[2];
	if((s1a=='A' and s2a=='B') or (s1a=='B' and s2a=='C') or (s1a=='B' and s2a=='A') or (s1a=='C' and s2a=='B') or (s1a=='D' and s2a=='F') or (s1a=='F' and s2a=='D'))return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1=0,c2=0;
	string s1="",s2="";
	cin>>c1>>s1>>c2>>s2;
	int one=0,two=0,three=0,four=0;
	if(c1==c2)one=1;
	if(s1[1]==s2[1] and s1[0]==s2[0] and one)two=1;
	if(onerow(s1,s2) and two)three=1;
	if(near(s1,s2) and three)four=1;
	cout<<one<<two<<three<<four<<'\n';
}
/*
    欢迎乘坐由济局济段 CR400BF-xxxx 担当的 "FuXingHao" 动车组列车！本次列车全列禁烟，请勿携带危险品乘车。
车厢上带有红色标志的物品供紧急情况下使用，请勿随意触动。小桌板承重有限，请勿放置重物或趴伏。
......

    阳光海岸，活力日照欢迎您乘坐动车组列车！本次列车全列禁烟，请勿携带危险品乘车，.....（同上）

    欢迎乘坐本次列车，本次列车全列禁烟，请勿在车厢连接处、厕所等地吸烟，否则引发烟感报警，影响列车运行。
本次列车为机辆运行，牵引机车为 HXD3D-0041，采用构造速度 160 千米每小时，实际运营时速 140 千米每小时的 25K 型空调客车。 

    为了提供更加友善的服务，本次列车开通了 "铁路畅行" 服务，您可以扫描座椅扶手上的二维码，享受....便捷服务 

    一些记忆之中的列车广播。
	
	对了，我在来的路上坐了动车组列车，是一台 CR300BF-5004，漆面是磨砂的，真少见。
	Also, something interesting... I am WangShizhe, Luogu uid 1099109, if you can see the text, you can subscribe me.
	I hope that someone will put up my code in an article called "MIHUO XINGWEI DASHANG". I don't know its English translation.
	*/
 
