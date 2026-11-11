#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		string a,b;
		a+=s1[0];
		a+=s1[1];
		b+=s2[0];
		b+=s2[1];
		if(a!=b){
			cout<<"1000";
			return 0; 
		}else{
			if(!((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))){
				cout<<"1100";
				return 0;
			}else{
				if(abs(s1[2]-s2[2])==1||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
					cout<<"1111";
					return 0;
				}else{
					cout<<"1110";
					return 0;
				}
			}
		}
	}
	return 0;
}//注意m n顺序 RP++
//8：16 建文件夹-ing希望能入选luogu游记awa！
//在考场外听人说今天是某光头男子的生日？不知道真假。。。 
//可恶，山东考生上了高中就不能来j组了。。。不可以戏顽童了qwq，明年就高一了。。。好快！
//开始了awa！excited~
/* Trick||Treat!
吓死我了，t1输出数字0000结果只有一个0，调了半天。。。还好多测了点特殊数据 
可恶。。。t2只能暴力打68分qwq
继小学组按位异或前缀和以后又来了个按位与dp。。。神了，考场搓dp希望不要爆炸
哈哈哈哈哈哈！仰天大笑入考场，我辈岂是蓬蒿人！，搓成功了，但是是二维的，尝试改一维-ing
斯。。。这按位与dp怎么压缩啊qwq别搞啊，样例怎么又不过了qwq
没招了，改回二维更不对了，直接re。。。
不生气不生气，吃根ccs（雪芽味的联动原神）好吃！很清香awa
准备采用“分治”算法，其实是m=1，2，3时分别写个程序hhh小的就暴力，大的尝试不一定对的算法 
现在才注意到2*10^5是20万。。。这不压缩则么玩啊。。。 
压了，但莫名少了1是怎么回事qwq！！！！急急急
 
*/

