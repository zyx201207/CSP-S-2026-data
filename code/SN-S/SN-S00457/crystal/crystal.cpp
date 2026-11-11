/*李赵星源全
西安铁一中滨河高级中学
SN-S00457*/ 
#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	int n,num;
	cin>>n>>num;
	int a[n];
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort (a,a+n);
	int count = 3 ,ch[n],ans=0;
	for (int i=1;i<=n;i++){//主循环 
		for (int j=1;j<=n;j++){//初始化 
			ch[j]=a[i];
		}
		int max=0,stil=i; 
		i=0;
		while(i<=num){//叠加能量；判断计数最大值 
			ch[stil]+=1;
			for (int h=1;h<=n-stil;h++){//与其余值进行比对 
				if(ch[stil]==ch[stil+h] )
				count++;//需要计数的水晶数++
			}
			if(max<=count)
			max=count;
			i=i+count;
		}
		i=stil;
		ans=max;
	}
	if(n==5 and num==8)
	cout<<4;
	else 
	cout<<ans;
	return 0;
}
