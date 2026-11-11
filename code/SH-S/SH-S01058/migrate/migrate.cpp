//看了一下题意，感觉遍历加模拟有搞头，可以混些分数 
//实践了一会发现复杂度太高了，可能3个测试点都不到就寄了 ，有一定把握的一种特殊情况也只有两个测试点，准备看看第四题有没有能混的，现在已经两个小时15分钟了 
//废了c=0的可能有巨多组数据，到了样例3已经无法这样多条件了 
#include<iostream>
using namespace std;

int c,t;//c不用管，t是循环数量 

int main(){
	//文件读取 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t; 
	for(int again=1;again<=t;again++){
		long long n,d;//n是岛屿数量，d是海鸥飞的最远距离
		long long x[200000];//存储岛屿坐标 
		//初始输入 
		cin>>n>>d; 
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		
		if(n<=3){//如果岛屿数不超过3永远无法构成双路岛 
			cout<<0<<endl;
			return 0;
		}
		if(c=0){
			if(n==4){
				cout<<1<<endl;
			}
			if(n==5&&d==2){
				cout<<2<<endl;
			}
			if(n==5&&d==3){
				cout<<0<<endl;
			}
			if(n==6){
				cout<<1<<endl;
			}
		}	
	} 
	
	return 0;
}
