#include<bits/stdc++.h>
using namespace std;
int l;
char a[1000000000];//存字母 
char a2[300000];
long long int b[80000000];//保险起见开long 存计量数 
int b1[300000];//前一半 
int b2[300000];//后一半 
int b3[300000];//后一半备份 
//回文 贪心 把字符串分成两半 将后面改成与前面的镜像 由于数据范围，直接输入可能会超时 
//所以判断回文，看后面是否与前面镜像，不能暴力遍历 
//没时间只能暴力 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b1[i]>>a2[i];
		l+=b1[i]; 
	}
	if(n==1||l==1){
		cout<<"0";
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=b1[i];j++){
			cnt++;
			a[cnt]=a2[i];
		}
	}
	//for(int i=1;i<=l;i++){
	//	cout<<a[i]; 
	//}
	int di;
	if(l%2==0){
		di=l/2;
	}
	else{
		di=l/2+1;
	}
	int ans=0;
	for(int i=1;;i++){
		if(a[i]!=a[l]){
			ans++;
		}
		l--;
		if(l==di){
			break;
		}
	}
	cout<<ans;
return 0;
}

