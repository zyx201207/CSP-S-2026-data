//chenjingxuan xianshidibashijiuzhongxue SN-J00683
#include<bits/stdc++.h>
using namespace std;
int a[500000],s[300000];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		for(int j = 1;j<i;j++){
			if(a[j] = a[i]){
				for(int n = j+1;n<=i;n++)a[n] = 0;
			}
		}
	}
	for(int i = 1;i<=n;i++){
		s[a[i]]++;
	}
	for(int i = 1;i <= n;i++)
	if(s[i] != 0)cout << s[i] << ' '; 
	return 0;
}
