#include <bits/stdc++.h> 
using namespace std;
int n,m,a[500005],put[300005],put_size,have[300005];
bool nput(int p){
	for (int i=0;i<=put_size;i++){
		if (p==put[i]){
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	stack<int> x;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=1;i<=n;i++){
		//i局从i开始 
		for (int j=i;j<=n;j++){
			//第j张牌 
			if (nput(a[j])){
				x.push(a[j]);
				put[put_size]=a[j];
				put_size++;
			}else{
				//有重复 
				while(x.top()!=a[j]){
					int l=x.top();
					x.pop();
					for (int p=0;p<=put_size;p++){
						if (put[p]==l){
							put[p]=0;
						}
					}
				}
			}
		}
		//游戏暂时结束 
		for (int y=0;y<=put_size;y++){
			have[put[y]]++;
			put[y]=0;
		}
		put_size=0;
		while(x.size()!=0){
			x.pop();
		}
		cout << endl;
	}
	for (int i=1;i<=m;i++){
		cout << have[i] <<" ";
	}
}
