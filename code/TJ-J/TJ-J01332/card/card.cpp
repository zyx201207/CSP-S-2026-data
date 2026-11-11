#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200050];
int d[200050]={0};
int ans[300050]={0};
int temp=0;
//大概有点分？ 
//找到x返回下标，没找到返回-1 
int findnum(int x){
	for(int i=0;i<temp;i++){
		if(d[i]==x){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//输入 
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	//外层 每个房间	
	for(int i=0;i<n;i++){
		temp=0;
		//每次跳过前i个 
		for(int j=i;j<n;j++){
			//查找 
			int sum=findnum(a[j]);
			//没有找到就添加 
			if(sum==-1){
				d[temp]=a[j];
				temp++;
			}
			//找到后删除右侧所有,留下新的 
			else{
				for(int k=sum;k<temp;k++){
					d[k]=0;
				}
				//刷新结尾 
				temp=sum;
				d[temp]=a[j];
				temp++;
			}
		}
		//对应牌的数量++ 
		for(int j=0;j<temp;j++){
			ans[d[j]]++;
		}
	}
	//输出 
	for(int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
