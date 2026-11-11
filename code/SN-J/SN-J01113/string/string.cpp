#include<bits/stdc++.h>
using namespace std;
//余俊辰 sn-j01113 西安市曲江第一学校 
const int N=1e8+100000;
char c;
int a[N],n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	long long num=0;
	for(int i=1;i<=n;i++){
		int p;
		cin>>p>>c;
		int k=c-'a';
		for(int i=num+1;i<=num+p;i++)a[i]=k+1;
		num+=p;
	}
//	for(int i=1;i<=num;i++)cout<<a[i]<<" ";cout<<endl;//cout<<num;
	long long ans=0;
	for(int i=1;i<=num/2;i++){
/*		cout<<i<<" "<<num-i+1<<" "<<ans;*/
		if(a[i]!=a[num-i+1])++ans;
	}
	cout<<ans<<endl;
	return 0;
}
//3 2 a 2 b 1 c
