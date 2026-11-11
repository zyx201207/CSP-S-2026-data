//kao hao:SH-J00674   xing ming:wang ge   xue xiao:yan an pei zhi zhong xue
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[500010];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	int s = 0;
	int arr2[500010] = {0};
	int arr3[500010] = {0};
	int q = 0;
	for(int i = 0;i<n;i++){
		arr3[arr[i]] = 1;
	}
	for(int i = 0;i<n;i++){
		for(int j = s;j<i;j++){
			if(j == 0){
				arr2[j] = arr[j];
			}else{
				bool flag = 0;
				for(int k = 0;k<j-1;k++){
					if(arr2[k] != arr[k]){
						flag=1;
						break;
					}
				}
				if(flag == 1){
					for(int k = 0;k<j-1;k++){
						arr2[k] = 0;
					}
					s = 0;
					arr2[s] = arr[j];
				}else{
					arr2[s] = arr[j];
				}
				s++;
			}
		}
		for(int j = 0;j<500050;j++){
			if(arr3[j] == 1){
				for(int k = 0;k<j;k++){
					if(arr2[k] == arr3[j]){
						q++;
					}
				}
			}
		}
		cout<<q<<' ';
	}
	return 0;
}
