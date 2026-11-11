//姓名:陆坦仪
//考号:SN-J00839
//学校:西安市第三中学 
#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5;
long long n,a[N] = {},m;
int t[N] = {};//记录每个数字的二进制位数
int o[N] = {};//记录每个数字的二进制中的'1'的个数 
int g[N] = {};//记录交界索引 
int f(int x,int num){
	int ans = 0;
	while(x){
		if(x & 1)o[num]++; 
		x = x >> 1;
		ans++;
	}
	return ans;
}
int sum = 0; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++){
		t[i] = f(a[i],i);
//		printf("%d t[%d] = %d o[%d] = %d\n",a[i],i,t[i],i,o[i);
	}
	for(int cnt = 0,i = n,gi = 0;i >= 1;i--){
		if(m == cnt)break;
		if(t[i] != t[i + 1]){
			gi++;
			g[t[a[i]]] = i;
		}
		if(sum == 0){
			sum = a[i];
			cnt++;
		}else{
			cnt++;
			sum &= a[i];
			if(sum == 0 && gi > 1){
				//交界处出现问题
				gi--;
				i = g[t[a[i]] + 1];
			}
		}  
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7

*/
