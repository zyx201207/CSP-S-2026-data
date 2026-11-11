#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	char y;
}a[200010];
string s,t;
int n;
void solve1(){
	for(int i = 1;i <= n;i++){
		cin >> a[i].x >> a[i].y;
	}for(int i = 1;i <= n;i++){
		for(int j = 1;j<=a[i].x;j++){
			s+=a[i].y;
		}
	}
	int l = s.size();
	for(int i = l-1;i >= 0;i--){
		t+=s[i];
	}
	if(s==t){
		cout << 0;
	}else{
		int mid = (l+1)/2,cnt = 0;
		for(int i = 0;i < mid;i++){
			if(s[i]!=t[i]){
				cnt++;
			}
		}cout << cnt;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	solve1();
	return 0;
} 
