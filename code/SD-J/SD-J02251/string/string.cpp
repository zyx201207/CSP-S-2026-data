/*
9:11-
两个双指针跟踪，左右
如果有一边长一点 那么先不跳动
计算一下是否相同 相同为0 不同就是min
短的接着跳 然后继续比较 长的不懂 直到左边积累的和右边一样了
*/ 
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct node{
	char ci;
	long long ai;
};
node s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s[i].ai>>s[i].ci;
	}
	long long l=1,r=n;
	long long cntl=0,cntr=0;
	long long cntl2=0,cntr2=0;
	long long ans=0;
	while(l<r){
		int tmp=min(s[l].ai-(cntl-cntl2),s[r].ai-(cntr-cntr2));
		if(s[l].ci!=s[r].ci){
			ans+=tmp;
		}
		cntl+=tmp;
		cntr+=tmp;
		if(s[l].ai-(cntl-cntl2)<=0) {
			l++;
			cntl2=cntl;
		}
		 if(s[r].ai-(cntr-cntr2)<=0){
			r--;
			cntr2=cntr;
		}
		
	}
	cout<<ans<<endl;
	return 0;
}
/*
4
4 a 1 b 6 c 3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


*/
