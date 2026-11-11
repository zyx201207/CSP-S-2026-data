//多测要清空，审题要认真，认真检查对拍，防止变量重名 ，及时保存代码及副本 , 开ll，计算空间 
//yyc,ytz,lcl,lyh,mpy,ljh,sxz,sbh,bjh,xjy,cjr,emmm,7/3大神保佑
//注意freopen，检查题目名，仔细核对思路，不要着急，一定行
//20min读题 , T1 15min想40min写+调 , T2 25min想45min写+调 , T3 15min想20min写暴力+调试 , T4 15min想20min写暴力+调试
//240-60-75-40-40=25min ， 留至少10分钟检查校对 
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int c , t;
int main(){
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	cin >> c >> t;
	while(t--){
		int n , k;
		cin >> n >> k;
		if(c == 13 || c == 14){
			for(int i = 1 ; i < n ; i++){
				int u , v;
				cin >> u >> v;
			}
			cout << (((n + 1) / 2) - k) / 4 + 1<< '\n';
		}
	}
	return 0;
}
