//第一次看第一题就没想出来怎么计算，暴力都想不到怎么暴力……
//先把特殊情况写了。特殊情况自检通过，作此题时间以正好40分钟 
//忽然想到可能与平均值有关，到目前为止开考1小时
//鉴于前面读完整卷子t2一眼看过去没具体思路，所以希望在这里多花点时间定20分钟内 
//出什么问题了	
//C:\Users\Administrator\AppData\Local\Temp\cc2EKEpE.s	Error: value of 00000004a85aecb3 too large for field of 4 bytes at 0000000000000003 
//不知道哪错了感觉是内存爆了,二维数组的数据类型改小了也没用，不知道怎么了，只有这里做了修改，其他都是在动程序
//实在想不到，那么这版就没用了，也浪费了时间，祈祷测试点里能很多都是递增吧
//我又有一计,又失败，感觉以我现在的思维能力不能修复这个bug，这可能导致将近一半的测试点栽掉，但我尽力了 
//只剩40分钟了，我准备去攻坚t2 
#include<iostream>
using namespace std;

int n;//能量水晶数量 
int a[50005];//每颗水晶的能量值
long long m;//总共多少次加1的数量 
int plusnum=-1;//判断输入是否为特殊值：全部递增一。后续改为int可以直接用来计等差,-1代表不是等差 
long long sum[50005];//放置段的区间和 

int main(){
	//文件读取 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//初始输入 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];//在过程中计算总和省复杂度 
		int t=a[i]-a[i-1];
		if(i==2){//有了两个基准数后开始统计 
			plusnum=t;
		}
		if(t!=plusnum){//判断相较于上一个数这里是否是一个递增顺序 
			plusnum=-1;
		}
	}
	
	if(n==1){//总数为1没有讨论必要，一定为1直接输出过掉 
		cout<<1<<endl;
		return 0;
	}
	
	//关于数据完全递增一的处理 
	if(plusnum!=-1){//用-1判断是否为特殊值
		//用等差数列公式(1+x)*x/2的公式反推出来m能顺延到第几位(失败)
		//循环递减看能递减多少次(无编译错误)
		//观察特殊情况b，特殊请情况b只不是自增一而是不定差的等差数列，将这个稍作修改 
		int tmp=m;//取出m的数来使用 
		int count=0;//计数，计减了几次 
		while(tmp>0){//判断是否减光了 
			if(tmp-plusnum<0){//防止plusnum已经超过tmp 
				cout<<count+1<<endl;//输出答案还要加1因为未包含自己 
				return 0;//直接走 
			}
			tmp=tmp-plusnum;//减去 
			plusnum=plusnum+plusnum;//plusnum自己加自己 
			count++;//count自增 
		}
		cout<<count+1<<endl;//输出答案还要加1因为未包含自己 
		return 0;//直接走 
	} 
	
	//平均值……有了。
	//每段枚举（从1到1，从1到2.从1到三），将这段中的数相加，再加上可累加的数量
	//求出来的结果先取余，若有余数直接continue
	//若取余等于0直接除以这段里的数字数量，也就是取平均出一个数
	//若这个数是这段后面紧挨着的数，那么就对了，接下来持续向后面检查是否相等即可
	//手算两个样例全过，考虑的时间复杂度并不高都是数学运算，猜想可能为正解，因此多花些时间。猜想完善完毕以1小时10分钟
	//开考一个半小时，两个题目样例没问题，但出现bug，这个只能计算递增数据，一旦不递增就寄了

	//大概想出如何解决bug，但实现步骤麻烦，选择先看下一题 
	//bug解决：将分段再次分段重新计，遇到减了的就分段，那么可以想办法将代码换成一个泛用性强的函数 
	int ans;
	sum[0]=0;//初始化 
	for(int i=1;i<=n;i++){//枚举每一段 i也代表这段的数据数量 
		int tmp=sum[i]+m;//先取出来再算
		
		if(tmp%i!=0){//求出来的结果先取余，若有余数直接continue
			continue;
		}
		
		int numequal=tmp/i;//每次重置equal，equal是相等数的基准 
		if(numequal==a[i+1]){
			ans=i;//答案暂时就是现在的数的数量 
			for(int j=i+1;j<=n;j++){//从下一个数判断而非当前数判断 
				if(a[j]==numequal){//说明后续还有 
					ans++;
				}
				else{
					break;
				}
			}
		}
		else{
			continue;
		}
	} 
	cout<<ans<<endl;
	return 0;
}
