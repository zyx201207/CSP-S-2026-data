//李思奇 83中学 SN-J00644 
#include <bits/stdc++.h>
using namespace std;

int n,m,card[500001];
bool f[300001];
string desk = "";
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n>>m;
	for(int i = 1;i <= n;i++){
		cin >> card[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;i <= m;i++) f[i] = 0;
		for(int x = i;x<= n;x++){
			if(f[card[x]] == true){
				for(int y = 1;y < desk.size();y++){
					if(desk[y] - '0' == card[x]){
						for(int a = y;a < desk.size();a++)
					}
				}
			}
		}
	}
}
