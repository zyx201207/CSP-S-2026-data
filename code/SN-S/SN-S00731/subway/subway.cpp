#include<bits/stdc++.h>
using namespace std;
using u = unsigned long long;
u random(u a,u b){
	return (u)(((rand() + 1e7+7)) * ((rand() + 1e7+7))) % b + (b-a);
}
int n;
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout); 
	cin >> n >> n >> n >> n >> n;
	while(n--){
		cout << random(1,250000000) << "\n";
	}
} 
