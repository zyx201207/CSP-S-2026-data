#include <iostream>
#include <cstring>

using namespace std;
string s,a,c;
long long n,chat; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	if(n == 1){
		cout << 0;
		return 0;
	}
	for (int i  = 0 ; i < n ;i++){
		cin >> a>>c;
		for(int j = 0; j < a[i];j++){
			s[j] = c[i]; 
		}
	}
	int cnt = 0;
	for(int j = s.size(); j>=0;j--){
		if(c[j] != c[cnt]){
			chat++;
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
