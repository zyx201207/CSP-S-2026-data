#include<bits/stdc++.h>
using namespace std;
int n,m,r = 1;
bool djsy[3005];
int qbsy[3005];
int pd[5005];
int zm[5005];
void cp(int a){
	for(int z = 1;z < r;z++){
		if(zm[z] == pd[a]){
			for(int y = z;y < r;y++){
				zm[y] = 0;
			}
			r = z;
			break;
		}
	}
	zm[r] = pd[a];
	r++;
	return;
}
void tj(){
	for(int j = 1;j < r;j++){
		djsy[zm[j]] = true;
	}
	for(int j = 1;j <= m;j++){
		if(djsy[j] == true){
			qbsy[j]++;
		}
	}
}
void qk(){
	r = 1;
	for(int i = 0;i < 3005;i++){
		djsy[i] = false;
		zm[i] = 0;
	}
	for(int i = 3005;i < 5005;i++){
		zm[i] = 0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> pd[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = i;j <= n;j++){
			cp(j);
		}
		tj();
		qk();
	}
	for(int i = 1;i <= m;i++){
		cout << qbsy[i] << ' ';
	}
	return 0;
}
