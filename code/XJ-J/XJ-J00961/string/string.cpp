#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin >> a;
	long long sum = 0;
	char noi[1000000];
	char math[200005];
	int math_math = 0;
	int sum_input[200005];
 	for(int i = 0;i < a;i++){
		cin >> sum_input[i];
		sum = sum + sum_input[i];
		cin >> math[i];
		for(int j = 0;j < sum_input[i];j++){
			noi[math_math] = math[i];
			math_math++;
		}
	}
	long long ending = 0;
	int copy = sum / 2;
	if(sum % 2 == 0){
		for(int i = 0;i < copy;i++){
			if(noi[copy-i-1] != noi[copy+i]){
				ending++;
			}	
		}
	}	
	cout << ending;
	return 0;
}