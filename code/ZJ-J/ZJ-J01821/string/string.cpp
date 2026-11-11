/**
夜晚的凉风吹过身边
空荡荡的街头只剩想念
想念你天真无邪笑颜
回头你却早已经不见

这不堪的生活每天重演
这世间早已换了人间
灯边矗立着依旧耀眼
沉默在这无奈的从前 

天上的星空转啊转
我站在地上看了又看
终点的街道无人在
永远不存在的下一班

我站在原地看又看
回忆像相册翻了有翻 
人生本该如花绚烂
为何我的却如此的平淡 

——《拼接遗憾》 
**/
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Char{
	int num;
	char s;
} a[300500];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	long long sum=0;
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].s;
	}
	
	// 《RE:从零开始的CPP生活》
	
	int l=1,r=n,r1=0,r2=0;
	int less;
	while(l<=r){
		less=abs((a[l].num-r1)-(a[r].num-r2));
		
//		cout<<l<<" "<<r<<" "<<a[l].num<<" "<<a[r].num<<" "<<less<<" "<<a[l].num-r1<<" "<<a[r].num-r2<<endl;
		
		if(less!=0){
			if(a[l].s!=a[r].s){
				sum+=min(a[l].num,a[r].num);
			}
			if(a[l].num-r1<a[r].num-r2){
				r2=a[l].num;
				a[l].num=0;
				a[r].num-=r2;
				r2=0;
				r1=0;
				l++;
			}
			else if(a[l].num-r1>a[r].num-r2){
				r1=a[r].num;
				a[r].num=0;
				a[l].num-=r1;
				r1=0;
				r2=0;
				r--;
			}
		}
		else{
			if(a[l].s!=a[r].s){
				sum+=a[l].num;
			}
			a[l].num=0;
			a[r].num=0;
			r1=0,r2=0;
			l++,r--;
		}
	}
	cout<<sum;
	
	
	return 0;
}
