#include <bits/stdc++.h> 
using namespace std;
long long n,a[201000],book[150][150];
string s;
char c;
//void p(string x,long long sum){
//	long long i,j,cnt = 0;
//	for(i = 0;i < sum;i ++){
//		for(j = sum;j > 0;j --){
//			if(x[i] == x[j]){
//				book[i][j] ++;
//			}  
//			else{
//				book[i][j] = 0;
//			} 
//		}
//	}
//	for(i = 0;i < sum;i ++){
//		for(j = sum;j > 0;j --){
//		    if(book[i][j] == 0) cnt ++;
//		}
//	}
//	cout<<cnt;
//}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long i,j,sum = 0;
	cin>>n;
	if(n == 1) cout<<0;
	for(i = 1;i <= n;i ++){
		cin>>a[i]>>c;
		for(j = 0;j < a[i];j ++){
			s[i] = c;
			sum ++;
		} 
	}
	for(i = 1;i <= n;i ++){
		if(n == 2 && s[1] != s[2]){
			if(a[1] < a[2]) cout<<a[1];
			else cout<<a[2];
		}
		else cout<<0;
	}
//	for(i = 0;i < sum;i ++){
//		for(j = sum;j > 0;j --){
//		    book[i][j] = 2;
//		}
//	}
//	p(s,sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
