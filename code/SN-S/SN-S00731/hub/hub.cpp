#include<bits/stdc++.h>
using namespace std;
using u = unsigned long long;
u random(u a,u b){
	return (u)(((rand() + 1e7+7)) * ((rand() + 1e7+7))) % b + (b-a);
}
int n;
int main(){
	freopen("hub.in","r",stdin); 
	freopen("hub.out","w",stdout); 
	cin >> n >> n;
	while(n--){
		cout << random(0,5) << "\n";
	}
} 
