//王楷淳 SN-J00716 西安交通大学附属中学 
#include <bits/stdc++.h>
using namespace std;
int n,an;
long long sum;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i++){
		long long x;
		char a;
		cin >> x >> a;
		sum += x;
		for(int j = 0;j < x;j++){
			s += a;
		}
	}
	int b = s.size()+1;
	int j = sum-1;
	for(int i = 0;i < b/2;i++){
		if(s[i] != s[j]){
			an++;
		}
		j--;
	}
	cout << an;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
