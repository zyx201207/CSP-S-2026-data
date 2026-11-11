#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen(string.in,'r',stdin);
	freopen(string.out,'w',stdout);
	string s;//建立总字符串；
	int n;//分串数； 
	cin>>n;//输入分串数；
	long long a;//每串长度；
	char c;//每串内容；
	long long w=0;//当前位置； 
	bool p;//判断是否是回文数 
	long long num=0;//表示差异数字有多少 
	for(int i=1;i<=n;i++){//遍历每个分串 
		cin>>a;//输入本串a值 
		cin>>c;//输入本串c内容 
		for(int j=w;j<=w+a;j++){//遍历每个分串内部
			s[j]=c; 
			w+=a;//w是总长度 
		}
	}
	for(int i=0;i<w;i++){
		for(int j=w;j>0;j--){
			if(i=j){
				p=1;
				continue;
			}
			else{
				p=0;
				num++;
			}
		}
	}
	cout<<num; 
	//for(int i=0;i<w;i++){
		//cout<<s[i];
	//}
	return 0;
}
