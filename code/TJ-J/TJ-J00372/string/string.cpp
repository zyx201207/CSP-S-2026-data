#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("string","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,count1 = 0,cnt = 0;
	string zf1,Z[100000000];
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> a >> zf1;
		count1+=a;
		for(int j = count1-a-1;j<count1-1;j++){
			Z[j] = zf1;
		}
	}
	for(int k = 0;k<count1;k++){
		if(Z[k]!=Z[k+count1-1]){
			cnt++;
		}
	}
	cout << (cnt+1)/2;
	return 0;
}
