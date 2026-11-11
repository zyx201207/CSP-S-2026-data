
#include<bits/stdc++.h>

using namespace std;
//rp-=-INF
struct node1{
	int cn;
};
struct node2{
	node1 com;
};
struct vec{
	public:
		int a[1000000];
		void push_back(int x){
			a[til ++] = x;
			sz ++;
		}
		void pop_back(){
			til --;
		}
		void show(){
			for(int i = 0;i != til;i ++)
				cout << a[i] << ' ';
		}
	private:
		int til = 0, sz = 0;
};
/*

*/
node2 luogu;
vec a;
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	luogu.com.cn = 1e9 + 7;
//	a.push_back(1);
//	a.push_back(2);
//	a.push_back(3);
//	a.push_back(4);
//	a.pop_back();
//	a.push_back(5);
//	a.show();
	cout << luogu.com.cn;
	return 0;
}

