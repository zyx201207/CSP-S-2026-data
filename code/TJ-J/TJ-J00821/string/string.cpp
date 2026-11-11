#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	string arr;
	int num = 111110;
	int n, count = 0;
	long long a;
	char c;
	cin >> n;
	for (int i = 1;i <= n;i ++){
		cin >> a >> c;
		for (int j = count + 1;j < a + count + 1;j ++){
			arr[j] = c;
		}
		count += a;
	}
	int finish = arr.size();
	for (int i = 1;i <= (arr.size() - 1) / 2;i ++){
		if (arr[i] != arr[finish]){
			finish -= 1;
			num += 1;
		}
	}			
	cout << num;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
