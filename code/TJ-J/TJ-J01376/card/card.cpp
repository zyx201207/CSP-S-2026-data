#include<bits/stdc++.h>
using namespace std;
int n,m,a[500500],res[500500],deskshu[500500],maxd=0;
vector<int> desk;
//must delete the //    务必删除freopen的注释！！！ 
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxd) maxd=a[i];
	}
	for(int i=1;i<=n;i++){//n局 
		if(deskshu[a[i]]==0){//桌面上没有点数为k的牌 
			desk.push_back(a[i]);//把这张牌放在最右端 
			deskshu[a[i]]++;//当前桌面上这张牌的数量+1 
		}
		else
			for(int j=i+1;j<=maxd;j++) deskshu[j]=0;
	}
	for(int i=1;i<=n;i++) cout<<deskshu[i]<<" ";
	return 0;
}
