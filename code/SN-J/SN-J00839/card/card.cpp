//姓名:陆坦仪
//考号:SN-J00839
//学校:西安市第三中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010] = {};
int num[300010] = {};//记录每个数字牌第一次出现的位置索引
int sum[300010] = {};//记录每个数字牌的出现次数
int tab[500010] = {};//模拟桌面 
int r = 0;//距离 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	int r = 0;
	for(int i = 1;i <= n;i++){
		r = 0;
		memset(tab,0,sizeof tab);
		memset(num,0,sizeof num);
		for(int j = i;j <= n;j++){
			//a[j]表示当前牌的值 
			if(num[a[j]] == 0){
				//普通 
				num[a[j]] = ++r;
				tab[r] = a[j];
			}else{
				r = num[a[j]];
				for(int l = r + 1;l <= n;l++){
					num[tab[l]] = 0;
					tab[l] = 0;
				}
			}
		}
		for(int l = 1;l <= r;l++){
//			cout << a[l] <<" ";
			sum[tab[l]]++;
		}
//		cout << '\n'; 
	}
	for(int i = 1;i <= m;i++)cout << sum[i] <<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

*/
