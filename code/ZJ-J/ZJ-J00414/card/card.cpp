#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],dangqianpaidui[500010],dangqianxiabiao,meigeshuzizaimeijujieshuhoudechuxiancishu[500010];
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int o = 1;o <= n;o++)dangqianpaidui[o] = 0;
		dangqianxiabiao = 1;
		for(int j = i;j <= n;j++){
			dangqianpaidui[dangqianxiabiao] = a[j];
			for(int k = 1;k < dangqianxiabiao;k++){
				if(dangqianpaidui[k] == dangqianpaidui[dangqianxiabiao]){
					for(int p = k ;p <= dangqianxiabiao;p++){
						dangqianpaidui[p] = 0;
					}
					dangqianxiabiao = k - 1;
				}
			}
			dangqianxiabiao++;
		}
		for(int j = 1;j < dangqianxiabiao;j++){
			meigeshuzizaimeijujieshuhoudechuxiancishu[dangqianpaidui[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << meigeshuzizaimeijujieshuhoudechuxiancishu[i] << " ";
	}
	return 0;
}
