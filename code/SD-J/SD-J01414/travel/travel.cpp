//08:39 我怎么才开题……饭堂忘记解压缩了
//08:41 这 T1 看着怎么这么邪恶 
//08:43 看完了，有点基础赛 T1 的风格 
//08:48 这个 Backspace 怎么这么不好用 
//08:54 也是成功切掉了好吧 
//11:31 回来检查一下，本来总分就少要是这题挂了就完了 
//11:32 没什么问题，看看 T3T4 能不能多骗点 
#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
		puts("0000");
	else{
		putchar('1');
		string b1=" ",b2=" ";
		b1+=s1[0],b2+=s2[0];
		b1+=s1[1],b2+=s2[1];
		if(b1!=b2)
			puts("000");
		else{
			putchar('1');
			if(s1[2]=='D'||s1[2]=='F'){
				if(s2[2]=='D'||s2[2]=='F')
					puts("11");
				else
					puts("00");
			}else{
				if(s2[2]=='D'||s2[2]=='F')
					puts("00");
				else{
					if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'))
						puts("10");
					else
						puts("11");
				}
			}
		}
	}
	return 0;
} 
//本题分数 100pts 
