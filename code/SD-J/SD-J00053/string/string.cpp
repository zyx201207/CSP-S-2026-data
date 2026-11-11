#include <bits/stdc++.h>
using namespace std;

int a[1005];
int b[1005];
int c[1005];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,x_,cnt=0,pos,AC=0;
	string s;
	cin >> n;
	if (n%2==0){
		pos=n/2;
	}else{
		pos=n/21;
	}//判断pos位置
	
	char y_;//节点字符
	
	for (int i=0;i<n;i++){
		cin >> x_>> y_;
		for (int j=0;j<x_;j++){
			s[j+i]=y_;
		}
	}//组成s
	for (int i=0;i<pos;i++){
		a[i]=s[i];
	}
	for (int i=pos+1;i<=n;i++){
		c[i]=s[i];
	}
	for (int i=pos+1;i<=n;i++){
		AC++;
		b[i]=c[AC];
	}//以pos为轴取左右数组
	for (int i=0;i<s.size();i++) cout << s[i];
	cout << endl;
	if (n%2==0){
		for (int i=0;i<n;i++){
			if (a[i]!=b[i]) cnt++;
		}
	}//偶
	else{
		for (int i=0;i<n;i++){
			if (i==pos) break;
			if (a[i]!=b[i]) cnt++;
		}
	}//奇
	cout << cnt;
	return 0;
} 
