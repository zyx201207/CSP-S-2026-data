#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200000 + 7];

int SIZE = 0;
int st[200000 + 7];
bool cont[200000 + 7];
void push(int x){
	st[++SIZE] = x;
	cont[x] = true;
}
bool isContain(int x){
	return cont[x]; 
}
bool pop(){
	cont[st[SIZE]] = false;
	st[SIZE--];
}
int top(){
	return st[SIZE];
}
int ans[200000 + 7];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i =1;i<=n;i++){
		cin >> a[i];
	}
	for(int j = 1;j<=n;j++){
		for(int i = j;i<=n;i++){
			if(isContain(a[i])){
				while(top() != a[i]){
					pop();
				}
				pop();
			}
			push(a[i]);
		}
		for(int i = 1;i<=SIZE;i++){
			ans[st[i]]++;
		}
		while(SIZE){
			pop();
		}
	} 
	
	for(int i = 1;i<=m;i++) cout << ans[i] << " ";
	return 0;
} 
