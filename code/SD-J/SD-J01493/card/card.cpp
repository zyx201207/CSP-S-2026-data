#include<bits/stdc++.h>//大模拟，数据规模大，不知道是超时还是死循环 
using namespace std;
int table[300005];//从0开始 
int ans[300005];//bucket
int tanum=0;//桌面上可以插入（压入）的位置 
int find(int x){
	for(int i=0;table[i]!=0;i++){
		if(table[i]==x)return i;
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;//点数从1到m且至少出现1次 ,n=cardnum
	vector<int>constcard; 
	vector<int>card;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		constcard.push_back(x);
		card.push_back(x);
	}
//	cout<<"constcard:" <<endl;
//	for(int i=0;i<n;i++)cout<<constcard[i]<<' ';
//	cout<<endl;
	int k;
	for(k=1;k<=n;k++){//局循环 
		tanum=0;
		for(int i=0;i<n;i++){//reset
			card[i]=constcard[i];
			table[i]=0;
		}
//		cout<<"当前游戏第"<<k<<"局"<<endl<<"card数组初始化："<<endl;
//		for(int i=0;i<n;i++)cout<<card[i]<<' ';
//		cout<<endl;
		//use 0 to show what put away
		for(int i=k-1;i<n;i++){//put out card
			int p=find(card[i]);
//			cout<<"p:"<<p<<endl;
			if(p==-1){
				table[tanum]=card[i];//put in
				tanum++;
			}
			else{
				for(int j=p+1;table[j]!=0;j++){//put away
					table[j]=0;
				}
				tanum=p+1;
			}
//			cout<<"放牌完成，table="<<endl;
//			for(int j=0;table[j]!=0;j++){
//				cout<<table[j]<<' ';
//			}
		}
		for(int i=0;i<tanum;i++){//统计ans 
			ans[table[i]]++;
			
		}
	}
	for(k=1;k<=m;k++)cout<<ans[k]<<' ';
	return 0;
} 
//-static-libgcc
/*
4 3
1 2 1 3










*/
