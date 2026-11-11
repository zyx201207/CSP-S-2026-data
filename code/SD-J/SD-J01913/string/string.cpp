//因为数据较大，不能转换成字符串之后再比对（铁定TLE） 考虑直接用a数组进行双指针 
#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
struct node{
	int x,y;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int o;
		char p;
		cin>>o>>p;
		a[i].x=o;
		a[i].y=p-'a';
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].y==a[r].y){ 
			if(a[l].x<a[r].x){
				a[r].x=a[r].x-a[l].x;
				l++;
			}
			else if(a[l].x>a[r].x){
				a[l].x=a[l].x-a[r].x;
				r--;
			}
			//前面减完之后到这里有可能相等，所以用else if来避免这种情况发生（第一个样例最开始就这么错的，感谢样例1） 
			else if(a[l].x==a[r].x){
				l++,r--;
			}
		}
		if(a[l].y!=a[r].y){
			if(a[l].x<a[r].x){
				a[r].x-=a[l].x;
				cnt+=a[l].x;
				l++;
			}
			else if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				cnt+=a[r].x;
				r--;
			}
			else if(a[l].x==a[r].x){
				cnt+=a[l].x;
				l++,r--;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
