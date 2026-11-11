#include<bits/stdc++.h> 
using namespace std;
	//find how many words different in string
	//把 第一个字符串与最后一个字符串比长度
/*
	用小的那个和大的那个比较，如果不是是同一个字符就ans+=小的那个，
	并且把小的删掉，继续比(不会双头队列，用静态数组+双指针) 
	
	在求出大的-小的的差 继续重复
	比到没有了为止(两个指针位置相同)   /   mid被某个字符包裹，如aaaaa m aaaaa 检查如果只有同一个字符 方法:用变量wor记录while执行次数，如果n-wor==1就结束 
*/ 
const int N=2e5+10;
struct node{
	int num;
	string str;
	int len;
}a[N]; 
int n;
long long ans;
int l,r;
int main(){
	freopen("string6.in","r",stdin);
	freopen("6string.out","w",stdout);
	cin>>n;
	int sum=0; 
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].str;
		sum+=a[i].num;
		a[i].len=a[i].str.size();
	}
	//int mid=n/2+1;   这是假想出来的 
	l=1;r=n;//两个指针 
	int wor=0;//记录while执行次数 
	while(l!=r){//O(n)
		if(n-wor<=1)break;//结束条件1: mid被某个字符包裹，如aaaaa m aaaaa 检查如果只有同一个字符 方法:用变量wor记录while执行次数，如果n-wor==1就结束 
		
		//比较a[l]与a[r]的num数量，分情况讨论
		int lenn=min(a[l].num,a[r].num);
		//两个部分的字母不同
		if(a[l].str!=a[r].str){
			if(a[l].num>a[r].num){//1.a[l].num>a[r].num ->删右侧 
				r--;
				a[l].num-=lenn;
			}else if(a[l].num<a[r].num){
				l++;
				a[r].num-=lenn; 
			}else{//a[l].num=a[r].num
				l++;
				r--;
				wor++;//这里直接消掉了2段，所以多加一个 
			}
			ans+=lenn;
		}else{//相同也要删，不过不用加ans 
			if(a[l].num>a[r].num){//1.a[l].num>a[r].num ->删右侧 
				r--;
				a[l].num-=lenn;
			}else if(a[l].num<a[r].num){
				l++;
				a[r].num-=lenn; 
			}else{//a[l].num=a[r].num
				l++;
				r--;
				wor++;//这里直接消掉了2段，所以多加一个 
			}
		}
		wor++;
	}
	cout<<ans<<" ";
	return 0;//记得用scanf 和 printf 
}
