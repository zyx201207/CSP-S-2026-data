#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+6;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,diff,x[maxn];
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(n==1||n==2||n==3){
			cout<<0<<endl;
			continue;
		}
		else if(n==4){
			if((x[3]-x[1]<=d&&x[4]-x[1]<=d)||(x[2]-x[1]<=d&&x[4]-x[2]<=d)) cout<<2<<endl;
			else cout<<0<<endl;
			continue;
		}
		diff=x[2]-x[1];
		if(diff<d){
			cout<<0<<endl;
			continue;
		}
		cout<<n-4*(diff/d)<<endl;
	}
	return 0;
}/*定风波   苏轼
三月七日，沙湖道中遇雨，雨具先去，同行皆狼狈，余独不觉，已而遂晴，故作此词。 
莫听穿林打叶声，何妨吟啸且徐行。竹杖芒鞋轻胜马，谁怕？一蓑烟雨任平生。
料峭春风吹酒醒，微冷，山头斜照却相迎。回首向来萧瑟处，归去，也无风雨也无晴。
水调歌头  苏轼
明月几时有？把酒问青天。不知天上宫阙，今夕是何年。我欲乘风归去，又恐琼楼玉宇。高处不胜寒，起舞弄清影，何似在人间。
转朱阁，低绮户，照无眠。不应有恨，何时长向别时圆。人有悲欢离合，月有阴晴圆缺，此事古难全。但愿人长久，千里共婵娟。
居黄州定慧院寓居做作  苏轼
缺月挂疏桐，漏断人初静。谁见幽人独往来，飘渺孤鸿影。惊起却回头，有恨无人省。拣尽寒枝不肯栖，寂寞沙洲冷。*/ 