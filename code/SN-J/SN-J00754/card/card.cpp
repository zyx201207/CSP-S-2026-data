//SN-J000754 余炜杰 西安辅轮中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[114514];
int b[114514];
int M[114514];

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,cnt;
	cin>>n>>m; 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int k=0;k<n;k++){//共玩4局 
		//cout<<"第"<<k+1<<"局"<<'\n'; 
		cnt=0;//牌的数量 
		for(int j=k;j<n;j++){//（j-k）次发牌 
			int flag1=-1;//没有重复时flag1为-1，有重复时flag1是重复的数的下标 
			for(int i=0;i<=n;i++){//遍历现在的牌组b 
				if(b[i]==a[j]){
					flag1=i;//第i个数与发牌j重复，flag1就为i 
					break; 
				}
			}
			//cout<<"flag="<<flag1<<' '; 
			if(flag1==-1){
				b[cnt]=a[j];
				cnt++;//放入一张，牌就加一张 
			}
			else{
				for(int i=flag1+1;i<=cnt;i++){//去除这张牌及右侧所有牌再在右侧放这张牌等于去除这张牌的右侧所有牌 
					b[i]=0;
					cnt--;//去掉牌 
				} 
			}
			/*for(int i=0;i<=cnt;i++){//测试 
				cout<<b[i]<<' '; 
			} 
			cout<<'\n';*/
		}
		for(int i=0;i<=cnt;i++){//遍历b数组 
			M[b[i]]++;//计数数组M 
		} 
		for(int i=0;i<=cnt;i++){//清空b数组 
			b[i]=0; 
		} 
	}
	for(int i=1;i<=m;i++){
		cout<<M[i]<<' ';
	}
	return 0;
}
