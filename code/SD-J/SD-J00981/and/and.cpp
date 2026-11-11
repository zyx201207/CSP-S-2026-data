#include<bits/stdc++.h>
#define io ios::sync_with_stdio();cin.tie();cout.tie();
using namespace std;
int n,m;
int a[400005],ans=0;
bool cmp(int x,int y){
	return x>y;
}
void sc(int x){
	if(x==0){
		for(int i=1;i<=n;i++){
			int s=2147483647;
			for(int j=i;j<=i+m-1;j++){
				s&=a[j];
			}
			ans=max(ans,s);
		}
	}
	else{
		for(int i=n;i>=n;i--){
			int s=2147483647;
			for(int j=i;j>=i-m+1;j--){
				s&=a[j];
			}
			ans=max(ans,s);
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	io;
	cin>>n>>m;
	if(n>=2001&&m>10){
		int b=0,c=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			int s=a[i];
			if(a[i]!=i-1) c=1;
			while(s&&b==0){
				if(s%2==0){
					b=1;
					break;
				}
				s/=2;
			}
		}
		if(c==0){
			sc(1);
		}
		if(b==0){
			sort(a+1,a+1+n,cmp);
			cout<<a[m];
			return 0;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n,cmp);
		for(int i=n+1;i<=n+m+1;i++){
			a[i]=a[i-n];
		}
		sc(0);
	}
	cout<<ans;
	return 0;
}
//Trick||Treat!
/*
	9:32 跳了
	10:18 还是回来想吧
	10:24 &完后貌似会越来越小，贪心？ 
	10:29 按二进制排序怎么写？想一想
	10:30 总不能硬转吧
	10:32 被我自己气笑了，不就是普通排序吗（绝望 
	10:35 不对在{
		1000   16
		0111   15
		0101   9
		0001   1
	}情况下会有问题
	10:36 算了先写 排序nlogn 判断nm O(nm n2logn) 少的话nlogn 多的话n3logn 50pts 
	11:30 性质 75pts
	100101     100101
	  1110        100
	   100       0100
	0011
	1111
	1100
	1100
	
	11111
	00011
	00001
	01111
	00111
	
	1111
	1100
	1100
	0011
	
	11111
	01111
	00111
	00011
	00001
	
	1000   16
	0111   15
	0101   9
	0001   1
	
	
	
	
	
	1111
	1110
	1101
	1100
	1011
	1010
	1001
	1000
*/
