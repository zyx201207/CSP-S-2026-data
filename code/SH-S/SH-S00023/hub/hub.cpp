#include<bits/stdc++.h>
using namespace std;
void meow(int x){
	for(int i = 0;i < x;i++)cout << "meow ";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n;
	while(cin >> n){
		int a = n % 15;
		n /= 15;
		for(int i = 0;i < n;i++){
			meow(15);
			cout << "\n\n";
		}
		meow(a);
		cout << endl;
	}
	return 0;
}
