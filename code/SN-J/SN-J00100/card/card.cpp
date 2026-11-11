#include<bits/stdc++.h>
using namespace std;
int aaa[100000000];
int bbb[100000000];
int ccc[100000000];

int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a,b,c,d,w = 0,n,m,ans=0;
	string s,s1;
	cin>>n>>m;
	for (int i = 0;i<n;i++){
		cin>>aaa[i];//获取数据 
	}
	for (int i = 0;i<n;i++){//局数统计 
		w = 0;
		for (int j = i;j<n;j++){//手牌数统计 
			
			
			for (int k = 0;k<w;k++){ //遍历场上牌 
				if(bbb[k] == aaa[j]){//判断是否有相同牌
					for (int l = k;l<j;l++){
						bbb[l] == 0;//删除 
					}
					w = k;//统计位数 
				}
			}
			bbb[w] = aaa[j];
			w+=1;//场上牌数 
		}
		
		//for (int j = 0;j<w;j++){
			
		//	cout<<bbb[j]<<" ";
		//}
		//cout<<endl;
		
		
		
		
		
		
		for (int j = 0;j<w;j++){//遍历场上牌 
			for (int k = 1;k<=m;k++){//判断是否符合条件 
				if(bbb[j] == k){
					ccc[k]+=1;
					continue;
				}
			}
			bbb[j] = 0;//归零 
		}
		w = 0;
	}
	for (int i = 1;i<=m;i++){
		cout<<ccc[i]<<" ";
		ccc[i] = 0;
	}
	return 0;
} 
