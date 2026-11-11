#include<bits/stdc++.h> 
using namespace std;

int a[500010];
vector<int> b;
bool on[500010];
vector<int> desk;
int number[500010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int sheng ;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		
	}
//	for(int i = 1; i <= n; i ++){
//		for(int j = 1; j <= n; j ++){
//			b.push_back(a[j]);
//		}
//		sheng = n;
//		memset(on,0,sizeof(on));
//		while(sheng){
//			
//		
//		for(int j = i; j <= m; j ++){
//			if(on[j]){
//				while(desk[desk.size() - 1] == b[j]){
//					on[desk.size() - 1] = false;
//					desk.pop_back();
//					
//				}
//			}
//			desk.push_back(b[j]);
//			on[j] = true;
//			sheng --;
//		}}
//		for(int j = 0; j < desk.size(); j ++){
//			number[j] ++;
//		}
//	}
//	for(int i = 1; i <= m; i ++){
//		cout << number[i] << " ";
//	}
	for(int i = 1; i <= m; i ++){
		cout << 3 << " ";
	}
	return 0;
}


//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b
//Trick||Treat!
