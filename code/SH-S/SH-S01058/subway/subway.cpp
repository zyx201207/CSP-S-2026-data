//这一问仔细看完：数据数量特别多稍有不慎可能就弄混了
//关于题目是关于路径的最优，这个我自己基础也不牢固。
//决定先看一下特殊情况是否好写。不好写，数据太过于复杂，虽然有一个的确简洁了算法，但是只占20分，而可能写这20分可能花费很久调试，选择直接过 
//完蛋了，数据类型都建不起来，看不明白。打草稿写纸上更乱 
//尝试用c=0来猜
//老师通知样例有问题，先写别的c=0 
#include<iostream>
using namespace std;

int main(){
	//文件读取 
	freopen("subway1.in","r",stdin);
	
	freopen("subway.out","w",stdout);
	
	int c;
	cin>>c;//最重要 
	
	long long n,m,d,p;
	long long w[50005];
	int t[505][50005];
	cin>>n>>m>>d>>p;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	
	return 0;
}
